#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * 
 *  Finding the modular inverse for prime moduli using
 * 					 Euclidean division
 * 
 *  Given prime modulus m > a 
 *  	m = k.a + r
 *  	where k = [m / a] and r = m mod( a )
 * 
 * 
 */

int inv(int a, int m) {
	return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int extendedGCD(int a, int b, int& x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = extendedGCD(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a / b);
	return d;
}

// Finding the modular inverse for array of numbers modulo m
vector<int> invs(const vector<int> &a, int m) {
	int n = a.size();
	if (n == 0) return {};
	vector<int> b(n);
	int v = 1;
	for (int i = 0; i != n; ++i) {
		b[i] = v;
		v = static_cast<long long>(v) * a[i] % m;
	}
	int x, y;
	extendedGCD(v, m, x, y);
	x = (x % m + m) % m;
	for (int i = n - 1; i >= 0; --i) {
		b[i] = static_cast<long long>(x) * b[i] % m;
		x = static_cast<long long>(x) * a[i] % m;
	}
	return b;
}

int main() {
	// vector<int> a {1,2,3,4,5,6};

	// for (int x : invs(a, 10)) {
	// 	cout << x << '\n';
	// }

	cout << inv(25,12) << '\n';
}