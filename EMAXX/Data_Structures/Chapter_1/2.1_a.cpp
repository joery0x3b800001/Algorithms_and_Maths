#include <iostream>
#include <bit>
using namespace std;

const int MAX_N = 1e7+5;
const int K = 25;

// Function f() is a place-holder for (RMQ) or (RSQ)

int arr[MAX_N];
int st[K + 1][MAX_N];
// int lg[MAX_N + 1];

int log2_floor(unsigned long i) {
	return bit_width(i) - 1;
}

// int log2_floor(unsigned long i) {
// 	return i ? __builtin_clz11(1) - __builtin_clz11(i) : -1;
// }

int query(int L, int R) {
	int length = R - L + 1;
	// int i = lg[R - L + 1];
	// int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
	int k = log2_floor(length);
	int minimum = min(st[k][L], st[k][R - (1 << k) + 1]);
	return minimum;
}

int main() {
	int n;
	cin >> n;

	// lg[1] = 0; // pre-compute log table for sparse table.
	// for (int i = 2; i <= MAX_N; i++)
	// 	lg[i] = lg[i/2] + 1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	copy(arr, arr+n, st[0]);

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
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