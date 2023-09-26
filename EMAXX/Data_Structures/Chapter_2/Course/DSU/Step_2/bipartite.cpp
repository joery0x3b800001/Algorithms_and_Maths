// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/I
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, len, size_;

pair<int,int> get(int a) {
	if (parent[a] == a)
		return make_pair(a, 0);
	auto val = get(parent[a]);
	parent[a] = val.first;
	len[a] = (len[a] + val.second) % 2;
	return make_pair(parent[a], len[a]);
}

void _union(int a, int b) {
	auto valA = get(a);
	auto valB = get(b);
	if (size_[valA.first] > size_[valB.first])
		swap(valA, valB);
	parent[valA.first] = valB.first;
	len[valA.first] = (1 + valA.second + valB.second) % 2;
	size_[valB.first] += size_[valB.first];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k, x, y, shift = 0;
	cin >> n >> m;

	parent.resize(n);
	size_.resize(n, 0);
	len.resize(n, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> k >> x >> y;
		x = (x + shift) % n; y = (y + shift) % n;
		if (k == 0) {
			_union(x, y);
		}
		else
		{
			if (k == 1)
			{
				auto root_x = get(x);
				auto root_y = get(y);

				if (root_x.second == root_y.second) {
					cout << "YES\n";
					shift = (shift + 1) % n;
				}
				else cout << "NO\n";
			}
		}
	}
	return 0;
}