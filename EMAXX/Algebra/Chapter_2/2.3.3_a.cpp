#include <iostream>

using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpow(u64 base, u64 e, u64 mod) {
	u64 result = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			result = (u128)result * base % mod;
		base = (u128)base * base % mod;
		e >>= 1;
	}
	return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
	u64 x = binpow(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = (u128)x * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}


bool MillerRabin(u64 n, int iter=5) {
	if (n < 4)
		return n == 2 || n == 3;

	int s = 0;
	u64 d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		s++;
	}

	for (int i = 0; i < iter; i++) {
		int a = 2 + rand() % (n - 3);
		if (check_composite(n, a, d, s))
			return false;
	}
	return true;
}

int main() {
	int n; cin >> n;

	if (MillerRabin(n)) {
		cout << n << " is prime\n";
	} else {
		cout << n << " is not prime\n";
	}
}