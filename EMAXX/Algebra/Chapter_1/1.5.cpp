#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// Fibonacci numbers

/**
 * 
 * Properties of fibonacci numbers
 * 
 * 	Cassini's identity
 * 			F(n-1)*F(n-1) - F(n)^2 = (-1)^n
 * 
 * 	The addition rule
 * 			F(n+K) = F(k)F(n+1) + F(k-1)F(n)
 * 
 * 	Applying previous identity to the case k=n
 * 			F(2n) = F(n)*(F(n+1) + F(n-1))
 * 
 * 	If F(m) if multiple of F(n), then m is a multiple of n
 * 
 * 	GCD(F(m), F(n)) = FGCD(m, n)
*/

int fib(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}

pair<int,int> fib(int n) {
	if (n == 0)
		return {0, 1};

	auto p = fib(n >> 1);
	int c = p.first * (2 * p.second - p.first);
	int d = p.first * p.first + p.second * p.second;
	if (n & 1)
		return {d, c + d};
	else
		return {c, d};
}

struct matrix {
	long long mat[2][2];
	matrix friend operator*(const matrix& a, const matrix& b) {
		matrix c;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				c.mat[i][j] = 0;
				for (int k=0; k<2; k++)  {
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				}
			}
		}
		return c;
	}
};

matrix matpow(matrix base, long long n) {
	matrix ans { {
		{1, 0},
		{0, 1}
	}};

	while (n) {
		if (n&1)
			ans = ans*base;
		base = base*base;
		n >>= 1;
	}
	return ans;
}

unsigned long long fibmat(int n) {
	matrix base {{
		{1, 1},
		{1, 0}
	}};
	return matpow(base, n).mat[0][1];
}

int main() {
	// int n; cin >> n;
	// for (int i=0; i<n; i++) {
	// 	cout << fib(i).first << " " << fib(i).second << '\n';
	// }

	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cout << fibmat(i) << '\n';
	}
}