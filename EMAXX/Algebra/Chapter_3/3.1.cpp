#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

// Euler totient function..
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int main() {
	int n;
	cin >> n;

	for (int i=1; i <= n; i++) {
		// cout << phi(i) << '\n';
		cout << gcd(i, phi(i)) << '\n';
	}
}