// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
// Question - 1
#include <iostream>
#pragma GCC optimize("Ofast")
using namespace std;

const int MAX_N = 1e5;
int p[MAX_N], n;
string str;

int get(int x) {
	if (x == p[x])
		return x;
	return p[x] = get(p[x]);
}

void union_sets(int a, int b) {
	a = get(a);
	b = get(b);
	if (a != b)
		p[b] = a;
}

int main() {
	int m,a,b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> str >> a >> b;
		if (str == "union") {
			union_sets(a, b);
		}
		if (str == "get") {
			cout << ((get(a) == get(b)) ? "YES\n" : "NO\n");
		}
	}
}