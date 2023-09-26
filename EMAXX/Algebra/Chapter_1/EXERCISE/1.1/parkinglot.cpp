#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n; cin >> n;
	cout << 2*4*3*pow(4, n-3)+(n-3)*4*pow(3,2)*pow(4, n-4);
}