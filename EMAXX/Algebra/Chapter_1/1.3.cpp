#include <iostream>

using namespace std;

// Extended euclid's algorithm
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


/**
 * 
 * 
 * x = y1
 * y = x1 - y1*[a/b]
 * 
 * 
 *
*/

int extendedGCDIterative(int a, int b, int& x, int& y) {
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;

	// These two invariants hold true before the loop and after the loop
	// cout << x*a + y*b << " = " << a1 << '\n';
	// cout << x1*a + y1*b << " = " << b1 << '\n';
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}

	// cout << x*a + y*b << " = " << a1 << '\n';
	// cout << x1*a + y1*b << " = " << b1 << '\n';
	return a1;
}

int main() {
	int x, y;
	cout << extendedGCD(55, 80, x, y) << '\n';
	cout << x << " " << y << '\n';

	// cout << extendedGCDIterative(55, 80, x, y) << '\n';
	// cout << x << " " << y << '\n';
}