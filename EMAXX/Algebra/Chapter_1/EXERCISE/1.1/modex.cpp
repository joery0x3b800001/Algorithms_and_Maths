// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671
#include <iostream>

using namespace std;

int main() {
	int tc; cin >> tc;

	long long x,y,m;
	while(tc--) {
		cin >> x >> y >> m;
		x %= m;
		long long res = 1;
		while (y > 0) {
			if (y & 1)
				res = res * x % m;
			x = x * x % m;
			y >>= 1;
		}

		cout << res << '\n';
	}
}