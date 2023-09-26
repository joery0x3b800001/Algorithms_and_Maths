#include <iostream>
using namespace std;
// Sparse Table
// RMQ with Sparse Table
const int MAX_N = 1e5+5;
const int LOG = 17;

int a[MAX_N];
int m[MAX_N][LOG];

int query(int L, int R) {
	int length = R - L + 1;
	// int k = 0; // O(log(N))
	// while ((1 << (k + 1)) <= length) {
	// 	k++;
	// }
	int k = 31 - __builtin_clz(length); // O(1)
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}

	for (int k = 1; k < LOG; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
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
