// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
#include <iostream>
#include <vector>
using namespace std;

int n, m, p[1000005];

int pa(int x) {
	if (x == p[x]) return x;
	return p[x] = pa(p[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= n+1; i++) {
		p[i] = i;
	}
	char c;
	for (int i = 0, x; i < m; i++) {
		cin >> c >> x;
		if (c == '?') {
			if (pa(x) == n+1) cout << -1 << '\n';
			else cout << pa(x) << '\n';
		} else {
			p[x] = pa(x+1);
		}
	}
}