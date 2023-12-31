// https://codeforces.com/contest/1106/problem/F

#include <iostream>
#include <cmath>
#include <map>
#define N 210
using namespace std;
typedef long long LL;

const LL p = 998244353;
const LL g = 3;

int k;
LL n, m, b[N];

struct Matrix {
	int n;
	LL mat[N][N];

	Matrix() {
		n = 0;
		memset(mat, 0, sizeof( mat ));
	}

	Matrix(int _n, LL diag) {
		n = _n;
		memset(mat, 0, sizeof( mat ));
		for (int i = 0; i <= n; i++) {
			mat[i][i] = diag;
		}
	}

	Matrix(const Matrix &c) {
		n = c.n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = c.mat[i][j];
			}
		}
	}

	Matrix operator*(const Matrix &a) const {
		Matrix res = Matrix(n, 0);
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					res.mat[i][j] += mat[i][k] * a.mat[k][j];
					res.mat[i][j] %= (p - 1);
				}
			}
		}
		return res;
	}

	Matrix mat_pow(LL t) {
		Matrix base = Matrix(*this), res = Matrix(n, 1);
		while (t) {
			if (t & 1) {
				res = res * base;
			}
			base = base * base;
			t >>= 1;
		}
		return res;
	}
};

namespace GCD {
	LL gcd(LL a, LL b) {
		if (!b) return a;
		return gcd(b, a%b);
	}

	LL ex_gcd(LL a, LL b, LL &x, LL &y) {
		if (!b) {
			x = 1; y = 0;
			return a;
		}

		LL q = ex_gcd(b, a % b, y, x);
		y -= a / b * x;
		return q;
	}
}

namespace BSGS {
	LL qpow(LL a, LL b, LL p) {
		LL res = 1, base = a;
		while (b) {
			if (b & 1) {
				(res *= base) %= p;
			}
			(base *= base) %= p;
			b >>= 1;
		}
		return res;
	}

	LL inv(LL x,  LL p) {
		return qpow(x, p - 2, p);
	}

	map<LL, LL> tab;
	LL bsgs(LL a, LL b, LL p) {
		LL u = (LL) sqrt(p) + 1;
		LL now = 1, step;
		for (LL i = 0; i < u; i++) {
			LL tmp = b * inv(now, p) % p;
			if (!tab.count(tmp)) {
				tab[tmp] = i;
			}
			(now *= a) %= p;
		}
		step = now;
		now = 1;
		for (LL i = 0; i < p; i += u) {
			if (tab.count(now)) {
				return i + tab[now];
			}
			(now *= step) %= p;
		}
		throw;
		return -1;
	}
}

namespace SOL {
	LL solve(LL a, LL b, LL c) {
		if (c == 0) return 0;
		LL q = GCD::gcd(a, b);
		if (c % q) {
			return -1;
		}
		a /= q, b /= q, c /= q;
		LL res,  _;
		GCD::ex_gcd(a, b, res, _);
		(res *= c) %= b;
		while (res < 0) res += b;
		return res;
	}
}

int main() {
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &b[i]);
		b[i] %= (p - 1);
	}

	scanf("%lld %lld", &n, &m);

	Matrix A = Matrix(k, 0);
	for (int i = 1; i <= k; i++) {
		A.mat[1][i] = b[i];
	}

	for (int i = 2; i <= k; i++) {
		A.mat[i][i - 1] = 1;
	}

	A = A.mat_pow(n - k);

	LL res = SOL::solve(A.mat[1][1], p - 1, BSGS::bsgs(g, m, p));
	if (res >= 0) {
		printf("%lld\n", BSGS::qpow(g, res, p));
	} else {
		puts("-1");
	}
	return 0;
}