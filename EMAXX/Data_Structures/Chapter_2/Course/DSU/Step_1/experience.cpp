#include <bits/stdc++.h>
using namespace std;

template < class T >
struct dsu {
private:
	T _n;
	vector<T> _p;
	vector<T> _size;
	vector<T> _min;
	vector<T> _max;
	vector<T> _score;
	vector<T> _extra;

public:
	dsu(T n) :_n(n), _p(n, 0), _size(n, 1), _min(n, 0), _max(n, 0),
				 _score(n, 0), _extra(n, 0) {
		iota(_p.begin(), _p.end(), 0);
		iota(_min.begin(), _min.end(), 0);
		iota(_max.begin(), _max.end(), 0);
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
		_min[u] = std::min(_min[u], _min[v]);
		_max[u] = std::max(_max[u], _max[v]);
		_extra[v] = _score[u];
		return true;
	}

	bool relation(T u,  T v) {
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

	T min(T u) {
		if (u < 0 || u >= _n) {
			return 0;
		}
		T t = find_root(u);
		return _min[t];
	}

	T max(T u) {
		if (u < 0 || u >= _n) {
			return 0;
		}
		T t = find_root(u);
		return _max[t];
	}

	void score(T u, T num) {
		u = find_root(u);
		_score[u] += num;
	}

	T score(T u) {
		return u == _p[u] ? _score[u] : (_score[u] - _extra[u] + score(_p[u]));
	}
};


int main() {
	#if 1
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	#endif

	int n, m;
	cin >> n >> m;

	dsu<int> ds(n + 1);

	for (int i = 0; i < m; i++) {
		string op; int u, v;
		cin >> op;
		if (op == "join") {
			cin >> u >> v;
			ds.union_set(u, v);
		} else if (op == "add") {
			cin >> u >> v;
			ds.score(u, v);
		} else if (op == "get") {
			cin >> u;
			int res = ds.score(u);
			cout << res << '\n';
		}
	}
	return 0;
}