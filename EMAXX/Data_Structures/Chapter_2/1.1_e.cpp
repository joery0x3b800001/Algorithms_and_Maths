// Support distances up to representative

#include <iostream>
#include <array>
using namespace std;

const int MAX_N = 1e5+5;

// array<pair<int, int>, MAX_N> parent;
pair<int,int> parent[MAX_N];

int rank_[MAX_N];

void make_set(int v) {
	for (int i = 0; i < v; i++) {
		parent[i] = make_pair(i, 0);
		rank_[i] = 0;
	}
}

pair<int, int> find_set(int v) {
	if (v != parent[v].first) {
		int len = parent[v].second;
		parent[v] = find_set(parent[v].first);
		parent[v].second += len;
	}
	return parent[v];
}

void union_sets(int a, int b) {
	a = find_set(a).first;
	b = find_set(b).first;
	if (a != b) {
		if (rank_[a] < rank_[b])
			swap(a, b);
		parent[b] = make_pair(a, 1);
		if (rank_[a] == rank_[b])
			rank_[a]++;
	}
}

int main() {
	make_set(10);

	union_sets(1,2);
	union_sets(3,8);
	union_sets(4,7);
	union_sets(5,2);
	union_sets(3,2);

	for (int i = 1; i <= 10; i++) {
		auto res = find_set(i);
		cout << res.first << ", len " << res.second << '\n';
 	}
}