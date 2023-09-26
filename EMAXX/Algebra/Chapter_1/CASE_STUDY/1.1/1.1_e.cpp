#include <iostream>

using namespace std;

int mulmod(int a, int b, int m) {
	int res = 0;
	a %= m;

	while (b > 0) {
		if (b & 1) {
			res = (res + a)%m;
		}
		a = (a * 2)%m;
		b >>= 1;
	}
	return res;
}

int mulmodRecursive(int a, int b, int m) {
	if (a == 0) return 0;
	long result = mulmod2(a, b / 2);
	result = (result * 2) % m;
	if (b % 2 == 1){
		result = (result + a) % m;
	}
	return result;
}

int main() {
	int a, b, m;
	cin >> a >> b >> m;

	int result = mulmod(a,b,m);

	cout << a << "*" << b << "%" << " = " << result << '\n';

	return 0;
}