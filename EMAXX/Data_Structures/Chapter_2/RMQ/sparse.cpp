// Sparse Method
#include <iostream>
#include <vector>
using namespace std;


const int maxn = 1 << 22, lg = 22;
int par[maxn], ans[maxn], n, q, lg2[maxn];
int spt[lg][maxn];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
   for(int i = 0; i < n; i++)
		cin >> spt[0][i];
   for(int i = 2; i < n; i++)  lg2[i] = lg2[i >> 1] + 1;
   for(int k = 1; k < lg; k++)
		for(int i = 0; i + (1 << k) <= n; i++)
	   	spt[k][i] = max(spt[k - 1][i], spt[k - 1][(i + 1) << (k - 1)]);
   cin >> q;
   for(int i = 0, l, r; i < q; i++){
		cin >> l >> r, r++;
			cout << max(spt[ lg2[r - l] ][l], spt[ lg2[r - l] ][ r - (1 << lg2[r - l]) ]) << ' ';
   }
   cout << '\n';
   return 0;
}