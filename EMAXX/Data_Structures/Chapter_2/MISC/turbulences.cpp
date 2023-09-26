// https://weoi.org/wp-content/uploads/2023/07/WEOI-2023-Problemset-Editorial.pdf
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

long long revenue(int N, int K, vector<long long> A) {
	sort(A.begin(), A.end(), [](ll i, ll j) { return abs(i) < abs(j); });

	ll highesRevenue = 0ll;

	size_t i = 0;
	while (i < A.size() && A[i] == 0) {
		i++;
	}

	int positives[N];
	positives[N - 1] = A[N - 1] > 0;
	for (int j = N - 2; j >= 0; j--) {
		positives[j] = positives[j + 1] + (A[j] > 0);
	}

	ll x;
	ll sum = 0ll;
	int count_gt, count_lt, cnt_current;
	while (i < A.size()) {
		cnt_current = 1;
		sum += A[i];
		while (i + 1 < A.size() && abs(A[i + 1]) == abs(A[i])) {
			i++;
			cnt_current++;
			sum += A[i];
		}

		count_gt = positives[i] - (A[i] > 0);
		count_lt = N - i - 1 - count_gt;

		x = abs(A[i]);
		highesRevenue = max(highesRevenue, sum + x * (count_gt - count_lt - K));
		i++;
	}
	return highesRevenue;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << revenue(N, K, A) << endl;
	return 0;
}