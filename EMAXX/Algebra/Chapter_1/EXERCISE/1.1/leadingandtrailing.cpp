// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=1970
#include <iostream>
#include <cmath>

using namespace std;

const int64_t MAXN = 10000001;

int main() {
	int tc; cin >> tc;
	int64_t n, k;

	while (tc--) {
		cin >> n >> k;
		// k %= MAXN;
		int64_t res = 1;
		while (k > 0) {
			if (k & 1)
				res = res * n;
			n = n * n;
			k >>= 1;
		}

		string s1 = to_string(res).substr(0,3);
		string s2 = to_string(res%1000);
		cout << s1 << "..." << s2 << '\n';
	}
}