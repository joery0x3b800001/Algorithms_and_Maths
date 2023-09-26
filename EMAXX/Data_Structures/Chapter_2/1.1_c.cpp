#include <iostream>
#include <vector>
#include <random>
using namespace std;

const int MAX_N = 1e5+5;

int parent[MAX_N], idx[MAX_N];

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v]  =find_set(parent[v]);
}

// Linking by index / coin-flip linking

/**
 *  Both union by rank and union by size require that you store
 *  additional data for each set, and maintain these values
 *  during each union operation. There exist also a randomized
 *  algorithm, that simplifies the union operation a little bit:
 *  linking by index.
 * 
 * 
 * 
 *  In fact it can be proven, that this operation has the same time
 *  complexity as union by size. However in practice it is slightly
 *  slower than union by size.
*/

void make_set(int v) {
	parent[v] = v;
	idx[v] = rand();
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (idx[a] < idx[b])
			swap(a, b);
		parent[b] = a;
	}
}

// Random linking and path compression
int union_sets(int a, int b) {
	a = find_set(b);
	b = find_set(b);
	if (a != b) {
		if (rand() % 2)
			swap(a, b);
		parent[b] = a;
	}
}

// Applications and various improvements
/**
 * 
 * 	-> Connected components in a graph
 * 	-> Search for connected components in an image
 * 	-> Store additional information for each set
 * 	-> Compress jumps along a segment / Painting subarrays offline
*/
int main() {

}