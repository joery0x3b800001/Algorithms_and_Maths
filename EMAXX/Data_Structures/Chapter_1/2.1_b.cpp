#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e7+5;
const int K = 25;

long long st[K + 1][MAX_N];
long long arr[MAX_N];

long long query(int L, int R) {
	long long sum = 0;
	for (int i = K; i >= 0; i--) {
		if ((1 << i) <= R - L + 1) {
			sum += st[i][L];
			L += 1 << i;
		}
	}
	return sum;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	copy(arr, arr+n, st[0]);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << query(L, R) << endl;
	}
}