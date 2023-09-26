// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

template < class T >
struct DSU {
private:
	T _n;
	vector<T> _p;
	vector<T> _size;

public:
	DSU(T n) :_n(n), _p(n, 0), _size(n, 1) {
		iota(_p.begin(), _p.end(), 0);
	}

	T find_root(T u) {
		return (u == _p[u]) ? u : find_root(_p[u]);
	}

	bool union_set(T u, T v) {
		if (u < 0 || u >= _n || v < 0 || v >= _n) {
			return false;
		}

		u = find_root(u);
		v = find_root(v);

		if (u == v) {
			return false;
		}

		if (_size[u] < _size[v]) {
			swap(u, v);
		}
		_p[v] = u;
		_size[u] += _size[v];
		return true;
	}

	bool relation(T u, T v) {
		if (u < 0 || u >= _n || v < 0 || v >= _n) {
			return false;
		}
		return find_root(u) == find_root(v);
	}

	T size(T u) {
		if (u < 0 || u >= _n) {
			return 0;
		}
		return _size[find_root(u)];
	}
};

int main() {
	#if 1
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#endif

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
	}

	vector<pair<string, pair<int, int>>> op;
	string s;
	for (int i = 0, u, w; i < k; i++) {
		cin >> s >> u >> w;
		op.push_back({s, {u, w}});
	}

	vector<string> res;
	DSU<int> dsu(n+1);
	while (op.size()) {
		int u = op.back().second.first;
		int v = op.back().second.second;
		if (op.back().first == "cut") {
			dsu.union_set(u, v);
		} else {
			if (dsu.relation(u, v)) {
				res.push_back("YES");
			} else {
				res.push_back("NO");
			}
		}
		op.pop_back();
	}


	for (vector<string>::reverse_iterator it = res.rbegin(); it != res.rend(); ++it) {
		cout << *it << '\n';
	}
	return 0;
}