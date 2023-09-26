#include <iostream>

using namespace std;

// GCD using recursion
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

// GCD using ternary operator
int gcdTernary(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

// GCD using iterative
int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

// Binary GCD without using mod operation
int gcdBin(int a, int b) {
	if (!a || !b)
		return a | b;
	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do {
		b >>= __builtin_ctz(b);
		if (a > b)
			swap(a, b);
		b -= a;
	} while (b);
	return a << shift;
}

// LCM
int lcm(int a, int b) {
	return a * b / gcd(a,b);
}

int main() {
	// cout << gcd(10, 20) << '\n';
	cout << gcdBin(10, 20) << '\n';
}