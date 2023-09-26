// https://codeforces.com/contest/475/problem/D
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }
 
int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	auto v = readVector<int>(n);
	
	map<int, long long> results;
	
	map<int, int> divisors;
	map<int, int> nextDivisors;
	for (int i = 0 ; i < n ; i++) {
		nextDivisors.clear();
		for (auto &p : divisors) {
			nextDivisors[gcd(p.first, v[i])] += p.second;
		}
		nextDivisors[v[i]]++;
 
		swap(nextDivisors, divisors);
		for (auto &p : divisors)
			results[p.first] += p.second;
	}
	
	int q; cin >> q;
	while (q --> 0) {
		int x; cin >> x;
		cout << results[x] << endl;
	}
}