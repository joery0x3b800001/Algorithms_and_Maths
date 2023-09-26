#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x) {
	for (int d=2; d*d<=x; d++) {
		if (x%d == 0)
			return false;
	}
	return true;
}

long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1; // b >>= 1 % (m-1) if the m is primeds
	}
	return res;
}

bool probablyPrimeFermat(int n, int iter=5) {
	if (n < 4)
		return n == 2 || n == 3;

	for (int i=0; i<iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (binpow(a, n-1, n) != 1)
			return false;
	}
	return true;
}

int main() {
	int n; cin >> n;
	// for (int i=0; i<n; i++) {
	// 	if (isPrime(i)) {
	// 		cout << i << " is prime\n";
	// 	}
	// 	else cout << i << " is not prime\n";
	// }

	// if (probablyPrimeFermat(n)) {
	// 	cout << n << " is prime\n";
	// } else {
	// 	cout << n << " is not prime\n";
	// }

	cout << 2 + rand() % (n - 3);
}