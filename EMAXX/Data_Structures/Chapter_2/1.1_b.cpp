#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5+5;

int parent[MAX_N], size[MAX_N], rank_[MAX_N];
// In both approaches the essence of the optimization is the same:
// we attach the tree with the lower rank_ to the one with 
// the bigger rank_.

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

// Union by size of the trees as rank_
void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

bool areConnected(int a, int b) {
	return find_set(a) == find_set(b);
}

int main() {
	int n;
	n = 10;

	make_set(n);

	union_sets(0, 1);
	union_sets(2, 3);
	union_sets(4, 5);
	union_sets(6, 7);
	union_sets(8, 9);

	cout << "Are 0 and 1 connected? " << (areConnected(0, 1) ? "Yes" : "No") << endl;
	cout << "Are 2 and 4 connected? " << (areConnected(2, 5) ? "Yes" : "No") << endl;
}