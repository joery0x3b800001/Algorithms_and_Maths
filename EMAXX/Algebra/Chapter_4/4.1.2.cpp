#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
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

// Findign the modular inverse using extended euclidean algorithm
void  mod_inv(int a, int m) {
	int x, y;
	int g = extendedGCD(a, m, x, y);
	if (g != 1) {
		cout << "No solution!\n";
	}
	else {
		x = (x % m + m) % m;
		cout << x << '\n';
	}
}

// Finding the modular inverse for every number modulo m
void mod_inv1(int m) {
	vector<int> inv(m + 1);
	inv[1] = 1;
	for (int i = 2; i < m; ++i)
		inv[i] = m - (m/i) * inv[m%i] % m;

	for (int i = 0; i < m; ++i) cout << inv[i] << '\n';
}

int main() {
	int a, m;
	cin >> m;
	// mod_inv(a, m);
	// mod_inv1(m);

	mod_inv1(m);
}