// https://codeforces.com/problemset/problem/154/B
// More time and space complexity..
#include <iostream>
#include <set>
#include <vector>
#define vi vector<int>
#define ll long long

using namespace std;

const int MAXN = 1e5 + 5;
vi divisors[MAXN];
bool on[MAXN];
set<int> s[MAXN];

vi get_divisors(int n) {
	vi res;
	for (int i = 2; (ll)i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) res.push_back(n);
	return res;
}

void solve() {
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++)
		divisors[i] = get_divisors(i);

	while (m--){
		char op; int x; cin >> op >> x;
		if (op == '+') {
			if (on[x]) {
				cout << "Already on" << endl;
				continue;
			}

			int conflict = 0;
			for (auto i : divisors[x]) {
				if (s[i].size()) {
					conflict = *s[i].begin();
					break;
				}
			}

			if (conflict) cout << "Conflict with " << conflict << endl;
			else {
				cout << "Success" << endl;
				on[x] = true;
				for (auto i : divisors[x]) s[i].insert(x);
			}
		}
		else {
			if (!on[x]) cout << "Already off" << endl;
			else {
				cout << "Success" << endl;
				on[x] = false;
				for (auto i : divisors[x]) s[i].erase(x);
			}
		}
	}
}

int main() {
	solve();
}