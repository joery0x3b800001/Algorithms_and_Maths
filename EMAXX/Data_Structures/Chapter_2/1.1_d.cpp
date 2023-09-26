#include <iostream>
#include <array>
using namespace std;

const int MAX_N = 1e5+5;

struct dsu {
	int l,r,c;
	dsu() {}
	dsu(int ll, int rr, int cc) :l{ll}, r{rr}, c{cc} {}
};

array<dsu, MAX_N> query;

// Compress jumps along a segment / Painting subarrays offline
// Here we can use DSU with path compression

int parent[MAX_N], result[MAX_N];

void make_set(int v) {
	parent[v] = v;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void paintSubarraysOffline(int L, int m) {
	for (int i = 0; i <= L; i++) {
		make_set(i);
	}

	for (int i = m-1; i >= 0; i--) {
		int l = query[i].l;
		int r = query[i].r;
		int c = query[i].c;
		for (int v = find_set(l); v <= r; v = find_set(v)) {
			result[v] = c;
			parent[v] = v + 1;
		}
	}
}

int main() {
	int L = 10;
	int m = 5;

	query = {
		dsu(1, 5, 1),
      dsu(2, 8, 2),
      dsu(4, 6, 3),
      dsu(7, 9, 4),
      dsu(3, 7, 5)
   };

   paintSubarraysOffline(L, m);

   for (int i = 1; i <= L; i++) {
		cout << "Element " << i << " : " << result[i] << endl;
   }
}