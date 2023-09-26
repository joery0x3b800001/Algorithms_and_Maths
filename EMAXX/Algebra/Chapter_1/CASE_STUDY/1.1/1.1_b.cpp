#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100005
#define MOD 1000000007

int n, m;
vector<int> adj[MAXN];
int dp[MAXN][22];

void dfs(int u, int p) {
    dp[u][0] = 1;
    for(int i = 1; i <= 20; i++) {
        dp[u][i] = 0;
        for(int v : adj[u]) {
            if(v != p) {
                dp[u][i] += dp[v][i-1];
                dp[u][i] %= MOD;
            }
        }
    }
    for(int v : adj[u]) {
        if(v != p) dfs(v, u);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while(q--) {
        int x, y, k;
        cin >> x >> y >> k;
        int ans = dp[x][0] * dp[y][0];
        for(int i = 1; i <= 20; i++) {
            if(k & (1 << (i-1))) {
                ans *= dp[x][i];
                ans %= MOD;
                ans *= dp[y][i];
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}