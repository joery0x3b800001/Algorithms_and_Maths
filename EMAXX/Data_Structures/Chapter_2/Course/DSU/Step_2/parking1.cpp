// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
#include <iostream>
using namespace std;

int n, p[300006];

int pa(int x) {
	if (x == p[x]) return x;
	return p[x] = pa(p[x]);
}

void union_sets(int a, int b) {
	a = pa(a);
	b = pa(b);
	if (a != b)
		p[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n+1; i++) {
		p[i] = i;
	}

	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (pa(x) == n + 1)
			x = pa(1);
		cout << pa(x) << " ";
		union_sets(pa(x), pa(x)+1);
	}
}