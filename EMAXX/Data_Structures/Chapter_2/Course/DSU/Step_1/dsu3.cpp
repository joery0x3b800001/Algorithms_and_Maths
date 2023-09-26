// Question - 2(version-2)
#include <iostream>
#include <vector>
using namespace std;

struct dsu {
	dsu(int n) {
		parent.resize(n);
		rank_.resize(n, 0);
		max_elem.resize(n);
		min_elem.resize(n);
		size_.resize(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			min_elem[i] = i + 1;
			max_elem[i] = i + 1;
		}
	}

	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void unite(int a, int b) {
		a--; b--;

		a = find_set(a);
		b = find_set(b);

		if (a != b) {
		   if (rank_[a] < rank_[b])
		      swap(a, b);
		   parent[b] = a;
		   size_[a] += size_[b];
		   min_elem[a] = min(min_elem[a], min_elem[b]);
		   max_elem[a] = max(max_elem[a], max_elem[b]);
		   if (rank_[a] == rank_[b])
		      rank_[a]++;
		}
	}

	void get_set_info(int v) {
      v--;
      int root = find_set(v);
      cout << min_elem[root] << " " << max_elem[root] << " " << size_[root] << endl;
   }
private:
	vector<int> parent, rank_, size_, min_elem, max_elem;
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	dsu d(n);

	for (int i = 0; i < m; i++) {
	   string query; int u, v;
	   cin >> query >> u;
	   if (query == "union") {
	      cin >> v;
	      d.unite(u, v);
	   } else if (query == "get") {
	      d.get_set_info(u);
	   }
	}
	return 0;
}