// https://codeforces.com/problemset/problem/193/E
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e13;

int main() {
	int n;
	cin >> n;

	vector<long long> fib(n + 1);
	
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	for (long long i=3; i<=n; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
		if (fib[i] == n) {
			cout << i << '\n';
			return 0;
		}
	}
}