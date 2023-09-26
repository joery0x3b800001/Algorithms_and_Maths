#include <iostream>
#include <cmath>

using namespace std;

long long mult(long long a, long long b, long long mod) {
	return (__int128)a * b % mod;
}


// If GCC's type __int128 for 128-bit integer is not available then use
// long long mult(long long a, long long b, long long mod) {
// 	long long result = 0;
// 	while (b) {
// 		if (b & 1)
// 			result = (result + a) % mod;
// 		a = (a + a) % mod;
// 		b >>= 1;
// 	}
// 	return result;
// }

long long f(long long x, long long c, long long mod) {
	return (mult(x, x, mod) + c) % mod;
}

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long long rho(long long n, long long x0=2, long long c=1) {
	long long x = x0;
	long long y = x0;
	long long g = 1;
	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		g = gcd(abs(x - y), n);
	}
	return g;
}

long long brent(long long n, long long x0=2, long long c=1) {
	long long x = x0;
	long long g = 1;
	long long q = 1;
	long long xs, y;

	int m = 128;
	int l = 1;
	while (g == 1) {
		y = x;
		for (int i = 1; i < l; i++)
			x = f(x, c, n);
		int k = 0;
		while (k < 1 && g == 1) {
			xs = x;
			for (int i = 0; i < m && i < l - k; i++) {
				x = f(x, c, n);
				q = mult(q, abs(y - x), n);
			}
			g = gcd(q, n);
			k += m;
		}
		l *= 2;
	}
	if (g == n) {
		do {
			xs = f(xs, c, n);
			g = gcd(abs(xs - y), n);
		} while(g == 1);
	}
	return g;
}

int main() {
	cout << rho(2206637, 2, 1) << '\n';
	cout << brent(2206637, 1, 2) << '\n';
	cout << mult(2, 3, 10) << '\n';
}