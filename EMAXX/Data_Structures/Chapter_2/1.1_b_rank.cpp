// Union by rank_ based on the depth of the trees
// (more precisely, the upper bound on the tree depth,
// because the depth will get smaller when applying path compression).
void make_set(int v) {
	parent[v] = v;
	rank_[v] = 0;
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (rank_[a] < rank_[b])
			swap(a, b);
		parent[b] = a;
		if (rank_[a] == rank_[b])
			rank_[a]++;
	}
}