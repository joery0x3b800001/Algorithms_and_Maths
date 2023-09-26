#include <iostream>
#include <vector>
using namespace std;

// Goldbach variations where the prime number is made the product of two smaller primes
// It is prime number is made the sum of 
vector<long long> trial_division1(long long n) {
	vector<long long> factorization;
	for (long long d = 2; d * d <= n; d++) {
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

int main() {
	int n;
	cin >> n;
	vector<long long> res = trial_division1(n);

	for (auto x : res) cout << x << ' ';
}