#include <iostream>
using namespace std;

const int MAX_N = 200006;

struct Node {
	int  p;
	int r;
	int maxn;
};

Node node[MAX_N];

int merge(int x, int y) {
	node[y].p = x;
	node[x].maxn = max(node[x].maxn, node[y].maxn);
	return 0;
}

int assign(int x, int y) {
	node[y].p = x;
	node[y].maxn = node[x].maxn;
	return 0;
}

int get(int x) {
	if (node[x].p == x) return x;
	int y = get(node[x].p);
	assign(y, x);
	return y;
}

void _union(int x, int y)
{
	x = get(x);
	y = get(y);
	// if (x == y) return;
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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q, x, y, z;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		node[i].p = i;
		node[i].r = 0;
		node[i].maxn = i;
	}

	for (int i = 0; i < q; i++) {
		cin >> x >> y >> z;
		if (x == 1) {
			_union(y, z);
		} else if (x == 2) {
			for (int i = y; i <= z; i++) {
				_union(i, z);
			}
		} else if (x == 3) {
			if (get(y) == get(z)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}