#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 3e5+5;

struct Node {
	int  p;
	int r;
	int maxn;
};

Node node[N];

int merge(int x, int y) {
	node[y].p = x;
	node[x].maxn = max(node[x].maxn, node[y].maxn);
	return 0;
}

int assign(int x, int y) {
	node[y].p = x;
	node[y].maxn = node[x].maxn;
	return 0;
}

int get(int x) {
	if (node[x].p == x) return x;
	int y = get(node[x].p);
	assign(y, x);
	return y;
}

void _union(int x, int y)
{
	x = get(x);
	y = get(y);
	if (x == y) return;
	if (node[x].r == node[y].r) node[x].r++;
	if (node[x].r > node[y].r)
	{
		merge(x, y);
	}
	else
	{
		merge(y, x);
	}
}