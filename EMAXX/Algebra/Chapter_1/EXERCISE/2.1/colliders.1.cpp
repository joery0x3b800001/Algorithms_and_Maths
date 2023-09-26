// https://codeforces.com/problemset/problem/154/B
// More space complexity and less time complexity.
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())

typedef long long ll;
using namespace std;

const int MAX = 100002;
bool primes[MAX];
vi divs[MAX];
void sieve() {
	mem(primes, 1);
	primes[0] = primes[1] = 0;
	int d = 1;
	for (int i = 2; i  < MAX; i += d, d = 2) {
		if (primes[i])
			for (int j = i + i; j < MAX; j += i) {
				primes[j] = 0;
				divs[j].push_back(i);
			}

	}
}

int lamps[MAX];
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	sieve();

	rep(i,m) {
		char c;
		int k;
		scanf(" %c %d", &c, &k);
		if (c == '+') {
			if (lamps[k] == k) {
				printf("Already on\n");
				continue;
			}
			if(lamps[k]){
				printf("Conflict with %d\n", lamps[k]);
				continue;
			}
			rep(i,sz(divs[k])) {
				int d = divs[k][i];
				if (lamps[d]) {
					printf("Conflict with %d\n", lamps[d]);
					goto end;
				}
			}


			rep(i,sz(divs[k])) {
				int d = divs[k][i];
				lamps[d] = k;
			}
			lamps[k]=k;
			printf("Success\n");

		}

		else {
			if (lamps[k] != k)
				printf("Already off\n");
			else {
				rep(i,sz(divs[k])) {
					int d = divs[k][i];
					lamps[d] = 0;
				}
				lamps[k]=0;
				printf("Success\n");
			}
		}
		end: ;

	}
	return 0;
}