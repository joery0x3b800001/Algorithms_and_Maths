// Support the parity of the path length / Checking bipartiteness online

#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e5+5;

int rank_[MAX_N];
pair<int, int> parent[MAX_N];
bool bipartite[MAX_N];

// The unusual requirement of storing the parity of the path comes
// up in the following task: initially we are given an empty graph,
// it can be added edges, and we have to answer queries of the form
// "is the connected component containing this vertex bipartite?".


// To solve this problem, we make a DSU for storing of the components
// and store the parity of the path up to the representative for each
// vertex.

void make_set(int v) {
	parent[v] = make_pair(v, 0);
	rank_[v] = 0;
	bipartite[v] = true;
}

pair<int, int> find_set(int v) {
	if (v != parent[v].first) {
		int parity = parent[v].second;
		parent[v] = find_set(parent[v].first);
		parent[v].second ^= parity;
	}
	return parent[v];
}


void add_edge(int a, int b) {
	pair<int, int> pa = find_set(a);
	a = pa.first;
	int x = pa.second;

	pair<int, int> pb = find_set(b);
	b = pb.first;
	int y = pb.second;

	if (a == b) {
		if (x == y)
			bipartite[a] = false;
	} else {
		if (rank_[a] < rank_[b])
			swap(a, b);
		parent[b] = make_pair(a, x^y^1);
		bipartite[a] &= bipartite[b];
		if (rank_[a] == rank_[b])
			++rank_[a];
	}
}

bool is_bipartite(int v) {
	return bipartite[find_set(v).first];
}

int main() {

}