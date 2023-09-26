// https://codeforces.com/problemset/problem/687/B
#include <iostream>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
const long long N = 1200021;

int cntP[N], isP[N];

int main() {
	for (int i = 2; i < N; i++)
		if (!isP[i])
			for (int j = i; j < N; j += i)
				isP[j] = i;

	int n = in(), k = in();
	for (int i = 0; i < n; i++)
	{
		int x = in();
		while (x > 1)
		{
			int p = isP[x];
			int cnt = 0;
			while (x % p == 0)
			{
				cnt++;
				x /= p;
			}
			cntP[p] = max(cntP[p], cnt);
		}
	}
	bool ok = 1;
	while (k > 1)
	{
		ok &= (cntP[isP[k]] > 0);
		cntP[isP[k]]--;
		k /= isP[k];
	}
	cout << (ok ? "Yes\n" : "No\n");
}