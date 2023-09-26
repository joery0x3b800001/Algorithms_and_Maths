// https://codeforces.com/problemset/problem/17/A
#include <bits/stdc++.h>

const int N = 1000;

int main() {
	int n, k, cnt = 0;
	std::cin >> n >> k;

	std::vector<long long> pr(N, 0);
	int lp[N+1]{0};
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j<(int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
			lp[i*pr[j]] = pr[j];
	}

	long long sum = 0;
	for (int i=0; pr[i] <= n; i++) {
		for (int j=i+1; pr[j] <= n; j++) {
			sum += pr[i] + pr[j];
			if (sum + 1 == n || sum == n) ++cnt;
			sum = 0;
		}
	}
	std::cout << ((cnt >= k) ? "YES\n" : "NO\n");
}