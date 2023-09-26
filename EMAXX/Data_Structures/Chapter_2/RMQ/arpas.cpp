// Arpa's Trick
// https://codeforces.com/blog/entry/44351
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1 << 22;
int par[MAX_N], res[MAX_N], n, a[MAX_N], l[MAX_N], q, head[MAX_N], prv[MAX_N], st[MAX_N], tail;
int root(int v) {
	return par[v] == -1 ? v : par[v] = root(par[v]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(par, -1, sizeof par);
	memset(head, -1, sizeof head);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0, r; i < q; i++) {
		cin >> l[i] >> r, r--, l[i]--;
		prv[i] = head[r], head[r] = i;
	}

	for (int i = 0; i < n; i++) {
		while (tail-- && a[ st[tail] ] <= a[i])
			par[ st[tail] ] = i;
		st[++tail] = i;
		for (int qi = head[i]; qi >= 0; qi = prv[qi])
			res[qi] = a[root(l[qi])];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << ' ';
	cout << '\n';
	return 0;
}