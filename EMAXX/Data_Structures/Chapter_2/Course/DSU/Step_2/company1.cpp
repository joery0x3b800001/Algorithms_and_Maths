#include <iostream>
#include <vector>
using namespace std;

struct dsu {
	vector<int> p, rank_;

	dsu(int n) {
		p.resize(n);
		rank_.resize(n, 0);
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}

	int get(int x) {
		if (p[x] == x) return x;
		return p[x] = get(p[x]);
	}

	void union_sets(int x, int y) {
		x = get(x);
		y = get(y);
		if (rank_[x] == rank_[y]) rank_[x]++;
		if (rank_[x] > rank_[y]) {
			p[x] = y;
		}
		else p[y] = x;
	}

	void _union(int x, int y) {
		for (int i = x; i <= y; i++) {
			union_sets(i, y);
		}
	}
};

int main() {
	int n, q, x, y, z;
	cin >> n >> q;
	dsu ds(n);
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> z;
		if (x == 1) {
			ds.union_sets(z, y);
		}

		if (x == 2) {
			ds._union(y, z);
		}

		if (x == 3) {
			if (ds.get(y) == ds.get(z)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}