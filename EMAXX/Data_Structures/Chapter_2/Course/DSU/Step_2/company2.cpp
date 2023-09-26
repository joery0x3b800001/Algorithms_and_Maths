// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 200004;

int f[MAX_N];
int nex[MAX_N];

int getf(int a) {
	int x = a;
	while (f[x] != x) {
		x = f[x];
	}

	while (f[a] != x) {
		int j = a;
		a = f[a];
		f[j] = x;
	}
	return x;
}

void Union(int a, int b) {
	int fa = getf(a);
	int fb = getf(b);
	if (fa != fb) f[fb] = fa;
}

int main() {
	int n, q;
	while (~scanf("%d%d", &n, &q)) {
		for (int i = 1; i <= n; i++) {
			f[i] = i;
			nex[i] = i + 1;
		}

		int op;
		int a, b;
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &op, &a, &b);
			if (op == 1)  {
				Union(a, b);
			}
			else if (op == 2) {
				int tmp;
				for (int i = a; i <= b; i=tmp) {
					Union(a, i);
					tmp = nex[i];
					nex[i] = nex[b];
				}
			}
			else {
				if (getf(a) == getf(b)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
	return 0;
}