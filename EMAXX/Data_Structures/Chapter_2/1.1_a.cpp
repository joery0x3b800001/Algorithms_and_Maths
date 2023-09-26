#include <iostream>
using namespace std;

const int MAX_N = 1e5+5;

/**
 * 
 *  Disjoint Set Union / Union Find
 * 
 *  The basic interface of this data structure consists of only three
 *  	operations:
 * 	-> make_set(v) - creates a new set consisting of the new element v.
 *    
 * 	-> union_sets(a, b) - merges the two specified sets( the set in
 * 		 which the element a is located, and the set in which the
 *        element b is located)
 * 	
 * 	-> find_sets(v) - returns the representative  (also called leader)
 * 		  of the set that contains the element v. This representative
 * 		  is an element of its corresponding set. It is selected in each
 * 		  set by the  data structure itself (and can change over time,
 * 		  namely after union_sets calls). This representative can be used
 * 		  to check if two elements are part of the same set or not. a and
 * 		  b are exactly in the same set, if find_set(a) == find_set(b).
 * 		  Otherwise they are in different sets.
*/


/**
 * 
 *  To combine two sets (operation union_sets(a, b)), we first find the
 *  representative of the set in which a is located, and the representative
 *  of the set in which b is located. If the representatives are identical,
 *  that we have nothing to do, the sets are already merged. Otherwise, we 
 *  can simply specify that one of the representatives is the parent of the
 *  other representative - thereby combining the two trees.
*/

/**
 *  Finally the implementation of the find representative function (operation
 *  find_set(v)): we simply climb the ancestors of the vertex v until we reach
 *  the root, i.e. a vertex such that the reference to the ancestor leads to
 *  itself. This operation is easily implemented recursively.
*/

// Trie is aclled as digital tree ot prefix tree, is a type of k-ary tree search
// tree.

int parent[MAX_N];

void make_set(int v) {
	parent[v] = v;
}

// Naive Method
// int find_set(int v) {
// 	if (v == parent[v])
// 		return v;
// 	return find_set(parent[v]);
// }

// This optimization is designed for speeding up find_set.
/**
 * 
 *  The simple implementation does what was intended: first
 *  find the representative of the set (root vertex), and
 *  then in the process of stack unwinding the visited nodes
 *  are attached directly to the representative.
 * 
 * 
 *  The simple implementation does what was intended: first
 *  find the representative of the set (root vertex), and 
 *  then in the process of stack unwinding the visited nodes
 *  are attached directly to the representative.
 * 
*/

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

bool same_set(int a, int b) {
	return find_set(a) == find_set(b);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b)
		parent[b] = a;
}

int main() {
	int node_num, query_num;
	cin >> node_num >> query_num;

	for (int i = 0; i < node_num; i++) {
		make_set(i);
	}

	for (int i = 0; i < query_num; i++) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 0) {
			union_sets(u, v);
		} else {
			cout << same_set(u, v) << endl;
		}
	}
}