#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
	int a,b,c;
	cin >> a >> b >> c;

	vector<int> dp(c + 1, INF);
	dp[0] = 0;

	for (int i = 0; i <= c; ++i) {
		if (dp[i] != INF) {
			if (i + a <= c) {
				cout << i << "\n";
				dp[i + a] = min(dp[i + a], dp[i] + 1);
				cout << dp[i + a] << " " << (i + a) << " " << dp[i] + 1 << "\n";
			}

			if (i + b <= c) {
				dp[i + b] = min(dp[i + b], dp[i] + 1);
				cout << dp[i + b] << " " << (i + b) << " " << dp[i] + 1 << "\n\n";
			}
		}
	}

	if (dp[c] == INF) {
		cout << "No\n";
	}
	else {
		cout << dp[c] << '\n';
		cout << "Yes\n";
	}
	return 0;
}