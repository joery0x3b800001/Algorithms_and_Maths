#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// Prime numbers

/**
 * 
 *		Sieve of Eratosthenes
 * 
*/


// Sieving till root
void prime2(int n) {
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i=2; i*i<=n; i++) {
		if (is_prime[i])  {
			for (int j=i*i; j<=n; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	if (is_prime[n]) {
		cout << "is prime\n";
	} else {
		cout << "not prime\n";
	}
}


// Basic Sieve of eratosthenes
void prime1(int n) {
	vector<char> is_prime(n+1,true);
	is_prime[0] = is_prime[1] = false;
	for (int i=2; i<=n; i++) {
		if (is_prime[i] && (long long) i * i <= n) {
			for (int j=i*i; j<=n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	if (is_prime[n]) {
		cout << "is prime\n";
	} else {
		cout << "not prime\n";
	}
}

// Segmented sieve
int count_primes(int n) {
	const int S = 10000;
	vector<int> primes;
	int nsqrt = sqrt(n);
	vector<char> is_prime(nsqrt + 1, true);
	for (int i=2; i<=nsqrt; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j=i*i; j<=nsqrt; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	int result = 0;
	vector<char> block(S);
	for (int k=0; k*S<=n; k++) {
		fill(block.begin(), block.end(), true);
		int start = k * S;
		for (int p : primes) {
			int start_idx = (start + p - 1) / p;
			int j = max(start_idx, p) * p - start;
			for (; j<S; j+=p)
				block[j] = false;
		}

		if (k == 0)
			block[0] = block[1] = false;
		for (int i=0; i<S && start + i <= n; i++) {
			if (block[i])
				result++;
		}
	}
	return result;
}

// Finding primes in ranges
vector<bool> segmentedSieve(long long L, long long R) {
	// generate all primes up to sqrt(R)
	long long lim = sqrt(R);
	vector<bool> mark(lim + 1, false);
	vector<long long> primes;
	for (long long i = 2; i<=lim; ++i) {
		if (!mark[i]) {
			primes.emplace_back(i);
			for (long long j = i*i; j<=lim; j+=i) {
				mark[j] = true;
			}
		}
	}

	vector<bool> isPrime(R - L + 1, true);
	for (long long i : primes) {
		for (long long j = max(i*i, (L+i-1) / i*1); j<=R; j+=i)
			isPrime[j - L] = false;
	}

	if (L == 1)
		isPrime[0] = false;
	return isPrime;
}

// SegmentedSieve with no pregen (we don't pre-generate all prime numbers)
vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
	vector<bool> isPrime(R - L + 1, true);
	long long lim = sqrt(R);
	for (long long i = 2; i<=lim; i++) {
		for (long long j = max(i * i, (L+i-1) / i*i); j<=R; j+=i)
			isPrime[j - L] = false;
	}

	if (L == 1)
		isPrime[0] = false;
	return isPrime;
}

// Sieve of eratosthenes having linear time complexity
void check_primes() {
	const int N = 1000000;
	int lp[N+1]{0};
	vector<int> pr;

	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i*pr[j]] = pr[j];
	}
}

// Same as the above..
void linear_sieve() {
	const int N = 10000000;
	vector<int> lp(N + 1);
	vector<int> pr;

	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}

		for (int j = 0; i* pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
}

int main() {
	// int n;
	// cin >> n;

	// prime1(n);
	// prime2(n);
	// cout << count_primes(n) << '\n';
	check_primes();
	return 0;
}