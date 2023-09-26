#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

// Integer Factorization

// Trial division
vector<long long> trial_division1(long long n) {
	vector<long long> factorization;
	for (long long d=2; d*d<=n; d++) {
		while (n%d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

// Wheel factorization
vector<long long> trial_division2(long long n) {
	vector<long long> factorization;
	while (n % 2 == 0) {
		factorization.push_back(2);
		n /= 2;
	}

	for (long long d = 3; d*d<=n; d+=2) {
		while (n%d == 0)  {
			factorization.push_back(d);
			n /= 2;
		}
	}

	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

// Extended Wheel factorization
vector<long long> trial_division3(long long n) {
	vector<long long> factorization;
	for (int d : {2,3,5}) {
		while (n%d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	static array<int, 8> increments = {4,2,4,2,4,6,2,6};
	int i = 0;
	for (long long d = 7; d*d<=n; d+=increments[i++]) {
		while (n%d ==0) {
			factorization.push_back(d);
			n /= d;
		}
		if (i == 8)
			i = 0;
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

// Precomputed primes
vector<long long> primes;

vector<long long> trial_division4(long long n) {
	vector<long long> factorization;

	long long nsqrt = sqrt(n);
	vector<char> is_prime(nsqrt + 1, true);
	for (long long i=2; i<=nsqrt; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (long long j=i*i; j<=nsqrt; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	for (long long d : primes) {
		if (d * d > n)
			break;
		while (n%d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}

	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

/**
 * 
 * Fermat's factorization method
 * 	-> We can write an odd composite number n = p * q as the difference
 * 		of two squares n = a^2 - b^2
 * 		
 * 		n = ([p + 2]/2)^2 - ([p - q]/2)^2
*/

int fermat(int n) {
	int a = ceil(sqrt(n));
	int b2 = a*a - n;
	int b = round(sqrt(b2));
	while (b * b != b2) {
		a = a + 1;
		b2 = a*a - n;
		b = round(sqrt(b2));
	}
	return a - b;
}


/**
 * 
 * 
 * Pollard's (p - 1) method
 * 
 * 	-> It is very likely that at least one factor of a number
 * 		B-powersmooth for small B. B-powersmooth means, that
 * 		every power d^k of a prime d that divides p - 1
 * 		is atmost B.
 * 
 * 
*/

long long binpowMod(long long a, long long b, long long m) {
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

long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

long long pollards_p_minus_1(long long n) {
	long long nsqrt = sqrt(n);
	vector<char> is_prime(nsqrt + 1, true);
	for (long long i=2; i<=nsqrt; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (long long j=i*i; j<=nsqrt; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	int B = 10;
	long long g = 1;
	while (B <= 1000000 && g < n) {
		long long a = 2 + rand() % (n - 3);
		g = gcd(a,n);
		if (g > 1)
			return g;

		for (int p : primes) {
			if (p >= B)
				continue;
			long long p_power = 1;
			while (p_power * p <= B)
				p_power *= p;
			a = binpowMod(a, p_power, n);
			g = gcd(a - 1, n);
			if (g > 1 && g < n)
				return g;
		}
		B *= 2;
	}
	return 1;
}


int main() {
	int n; cin >> n;

	// auto res = trial_division4(n);
	// for (auto x : res) {
	// 	cout << x << "\n";
	// }

	cout << pollards_p_minus_1(n) << '\n';
	for (auto x : primes) cout << x << '\n';
	// cout << fermat(n) << '\n';
}