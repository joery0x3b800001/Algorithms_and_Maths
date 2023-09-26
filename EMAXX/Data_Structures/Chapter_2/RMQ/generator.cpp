#include <bits/stdc++.h>
using namespace std;

const int n = 1 << 22;
int a[n];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	srand(time(0));
	cout << n << '\n';
	iota(a, a + n, 0);
	random_shuffle(a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[ i == n - 1 ];
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		int l = rand() % n, r = rand() % n;
		if (l > r) swap(l, r);
		 cout << l << ' ' << r << '\n';
	}
	return 0;
}