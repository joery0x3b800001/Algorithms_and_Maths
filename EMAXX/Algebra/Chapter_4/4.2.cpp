#include <iostream>
using namespace std;
// Linear Congruence equation

/**
 * 
 *  The equation of the form: 
 * 		a.x = b mod (n)
 *  a, b, and n are given integersv and x in  unknown integer.
 * 
 *  It is required to find the value x from the interval[0, n-1]
 *  	on the number line there can be infinitely many solutions
 *    that will differ from each other in n.k, where k in any integer
 * 
 * 
 * 
*/

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int inv(int a, int m) {
	return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}


// Solution by finding the inverse element..
int inverse_element(int a, int n) {
	int x, b;
	b = 1;

	x = b * inv(a, n) % n;
	return x;
}

int main() {
	int a, n;
	cin >> a >> n;

	cout << inverse_element(a, n) << '\n';
	cout << gcd(a, n) << '\n';
}