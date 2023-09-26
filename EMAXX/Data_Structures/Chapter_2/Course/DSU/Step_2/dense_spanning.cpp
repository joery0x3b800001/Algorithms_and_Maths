// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/F
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 2e5+5;

struct Node {
	int p;
	int r;
	int maxn;
};

Node node[MAX_N];

int merge(int x, int y) {
	node[y].p = x;
	return 0;
}

int assign(int x, int y) {
	node[y].p = x;
	return 0;
}

int get(int x) {
	if (node[x].p == x) return x;
	int y = get(node[x].p);
	assign(y, x);
	return y;
}

void _union(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (node[x].r == node[y].r) node[x].r++;
	if (node[x].r > node[y].r)
	{
		merge(x, y);
	}
	else
	{
		merge(y, x);
	}
}

int cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		vector<int> edge = {x, y, w};
		edges.push_back(edge);
	}

	sort(edges.begin(), edges.end(), cmp);
	int minn = INT_MAX;
	for (int k = 0, pl; k < m; k = pl) {
		for (int i = 1; i <= n; i++) {
			node[i].p = i;
			node[i].r = 0;
		}
		long long res = 0;
		int num_edge = 0;
		int i, h, t;
		for (i = k; i < m; i++)
		{
			if (edges[i][2] == edges[k][2]) pl = i;
			int x = edges[i][0], y = edges[i][1], w = edges[i][2];
			x = get(x); y = get(y);
			if (x == y) continue;
			_union(x, y);
			res += w;
			num_edge += 1;
			if (num_edge == n - 1) break;
		}
		if (num_edge == n - 1) minn = min(minn, edges[i][2] - edges[k][2]);
		pl += 1;
	}
	if (minn != INT_MAX)
	{
		cout << "YES\n" << minn << '\n';
	}
	else cout << "NO\n";
	return 0;
}