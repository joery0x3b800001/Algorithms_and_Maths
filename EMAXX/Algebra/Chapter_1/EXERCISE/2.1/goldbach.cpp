#include <iostream>
#include <vector>
using namespace std;

// Goldbach variations where the prime number is made the product of two smaller primes
// It is prime number is made the sum of 
vector<long long> goldbach(long long n, int k) {
	vector<long long> factorization;
	for (long long d = 2; d * d <= n; d++) {
		while (n - d >= k) {
			factorization.push_back(d);
			n -= d;
		}
	}

	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> res = goldbach(n, k);

	for (long long i : res) {
		cout << i << ' ';
	}
}