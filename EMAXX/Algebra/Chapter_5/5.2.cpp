#include <iostream>
using namespace std;
// Gray code

/**
 * 
 * Gray code is a binary numeral system where two successive values
 * differ in only one bit.
*/

// Finding Gray Code
/**
 * Let's look ar the bits of number n and the bits of number G(n).
*/

int g(int n) {
	return n ^ (n >> 1);
}

int rev_g(int g) {
	int n = 0;
	for (; g; g >>= 1)
		n ^= g;
	return n;
}

int main() {
	cout << g(4) << endl;
	cout << rev_g(4) << endl;
}