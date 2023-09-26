#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

// Discrete logarithm

/**
 *  The discrete logarithm is an integer x satisfying the
 *  					equation: a^x = b.mod(m)
 * 
 *  x = n.p - q, where n is pre-selected constant. p is known as giant
 *  step bcz increasing it by one increases x by n.
 *  Similarly q is known as baby step.
 * 	->	 a ^(np - q) = b.mod(m)
 * 	-> (a and m are relatively prime):
 * 			a^(n.p) = b.a^(q).mod(m)
 * 	-> This new equation can be rewritten in a simplified form
 * 			f1(p) = f2(q)
*/

int powmod(int a, int b, int m) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * 1ll * a) % m;
		}
		a = (a * 1ll * a) % m;
		b >>= 1;
	}
	return res;
}

// Simplest implementation
int solve(int a, int b, int m) {
	a %= m; b %= m;
	// if (a == 0)
	// 	return b == 0 ? 1 : -1;
	int n = sqrt(m) + 1;
	map<int, int> vals;
	for (int p = 1; p <= n; ++p)
		vals[powmod(a, p * n, m)] = p;
	for (int q = 0; q <= n; ++q) {
		int cur = (powmod(a, q, m) * 1ll * b) % m;
		if (vals.count(cur)) {
			int res = vals[cur] * n - q;
			return res;
		}
	}
	return -1;
}

// Improved implementation
// Returns minimum x for which a ^ x % m = b % m, a and m are coprime.
int solve1(int a, int b, int m) {
	a %= m, b %= m;
	int n = sqrt(m) + 1;

	int an = 1;
	for (int i = 0; i < n; ++i)
		an = (an * 1ll * a) % m;

	unordered_map<int,int> vals;
	for (int q = 0, cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}

	for (int p = 1, cur = 1; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int ans = n * p - vals[cur];
			return ans;
		}
	}
	return -1;
}

// When a and m are not coprime..
/**
 * 
 *  g = gcd(a, m), and g > 1. Clearly a^x.mod(m) for every x >= 1
 *  will be divisible by g.
 * 
 * 	if g !| b there is no solution for x.
 *	if g | b, let a = ga1, b = gb1, m = gv1
 * 
 * 		a^x = b mod(m)
 * 		(g.a1).a^x-1 = gb1 mod(g.v1)
 * 		a1.a^x-1 = b1 mod (v)
 * 
 * 	The baby-step giant-step algorithm can be easily extended to
 *  solve k.a^x = b mod (x) for x.
 * 
 */

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

int solve2(int a, int b, int m) {
	a %= m, b %= m;
	int k = 1, add = 0, g;
	while ((g = gcd(a, m)) > 1) {
		if (b == k)
			return add;
		if (b % g)
			return -1;
		b /= g, m /= g, ++add;
		k = (k * 1ll * a / g) % m;
	}

	int n = sqrt(m) + 1;
	int an = 1;
	for (int i = 0; i < n; ++i)
		an = (an * 1ll * a) % m;

	unordered_map<int, int> vals;
	for (int q = 0, cur = b; q <= n; ++q) {
		vals[cur] = q;
		cur = (cur * 1ll * a) % m;
	}

	for (int p = 1, cur = k; p <= n; ++p) {
		cur = (cur * 1ll * an) % m;
		if (vals.count(cur)) {
			int res = n * p - vals[cur] + add;
			return res;
		}
	}
	return -1;
}

int main() {
	cout << solve(0, 1, 2) << endl;
	cout << solve1(0, 1, 2) << endl;
	cout << solve2(0, 1, 2) << endl;
}