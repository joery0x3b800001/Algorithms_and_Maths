// https://codeforces.com/blog/entry/48994

// Problem : Given array a of n integers, and q queries,
// for each query print the maximum value in range [L,R].

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 1e5 + 17;
int par[MAX_N], res[MAX_N], n, a[MAX_N], l[MAX_N], q;
vector<int> qu[MAX_N];
int root(int v) {
	return par[v] == -1 ? v : par[v] = root(par[v]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0, r; i < q; i++) {
		cin >> l[i] >> r, r--, l[i]--;
		qu[r].push_back(i);
	}

	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (st.size() && a[st.top()] <= a[i])
			par[st.top()] = i, st.pop();
		st.push(i);
		for (auto qi : qu[i])
			res[qi] = a[root(l[qi])];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << ' ';
	cout << '\n';
	return 0;
}