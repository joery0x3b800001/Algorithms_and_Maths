// https://codeforces.com/contest/26/problem/A
// https://stackoverflow.com/questions/17637896/count-distinct-prime-factors/17638003#17638003
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 3004;
int factorCount[N+1];

int main() {
	int n;
	cin >> n;

 	int i, j;
	for (i = 0; i <= N; i++) {
		factorCount[i] = 0;
	}

	for (i = 2; i <= N; i++) {
		if (factorCount[i] == 0) {
			for (j = i; j <= N; j += i) {
				factorCount[j]++;
			}
		}
	}

	// int count = 0;
	// for (int i=0; i<=n; i++) {
	// 	if (factorCount[i] == 2) {
	// 		++count;
	// 	}
	// }

	auto result = count_if(factorCount, factorCount+(n+1), [](const int a) { return (a == 2); });

	// cout << count << '\n';
	cout << result << '\n';
}