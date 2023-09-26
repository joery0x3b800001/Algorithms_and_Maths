// Vector + Binary Search

#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1 << 22;
int n, q, a[MAX_N], res[MAX_N], head[MAX_N], prv[MAX_N], l[MAX_N];
vector<int> v, qu[MAX_N];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(head, -1, sizeof head);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0, r; i < q; i++) {
		cin >> l[i] >> r;
		prv[i] = head[r], head[r] = i;
	}

	for (int i = 0; i < n; i++) {
		while (v.size() && a[v.back()] <= a[i]) v.pop_back();
		v.push_back(i);
		for (int qi = head[i]; qi >= 0; qi = prv[qi])
			res[qi] = a[*lower_bound(v.begin(), v.end(), l[qi])];
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << ' ';
	cout << '\n';
	return 0;
}