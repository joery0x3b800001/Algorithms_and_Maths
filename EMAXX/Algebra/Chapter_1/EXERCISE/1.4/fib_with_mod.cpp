#include <vector>
using namespace std;

int main() {
	int n, r;
	cin >> n >> r;

	vector<int> fib(n + 1);
	fib[0] = 1;
	fib[1] = 1;

	for (int i=2; i<=n; i++) {
		fib[i] = (fib[i-1] + fib[i-2]) % r;
	}

	int res = (2 * (fib[n] + fib[n - 1])) % r;
	cout << res << '\n';
}