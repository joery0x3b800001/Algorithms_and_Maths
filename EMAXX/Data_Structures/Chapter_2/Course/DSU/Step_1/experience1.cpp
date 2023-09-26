#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

const long long mod = 998244353;
const long long inf = 1e18;

class DSU {
    vector<int>par,exp,sizz;

public:
    DSU(){}

    DSU(int n) {
        for(int i=0;i<=n;i++) {
            par.push_back(i);
            exp.push_back(0);
            sizz.push_back(1);
        }
    }

    pair<int,int> find_set(int s) {
        if(par[s] == s) {
            return make_pair(s,exp[s]);
        }
        auto parent = find_set(par[s]);
        par[s] = parent.first;
        exp[s] += parent.second-exp[parent.first];
        return make_pair(par[s],exp[s]+exp[par[s]]);
    }

    void union_set(int u,int v) {
        u = find_set(u).first;
        v = find_set(v).first;

        if(u == v) return;

        if(sizz[u] > sizz[v]) swap(u,v);

        par[u] = v;
        exp[u] -= exp[v];
        sizz[v] += sizz[u];
    }

    void add_experience(int x,int v) {
        x = find_set(x).first;
        exp[x] += v;
    }

};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n,m;
    cin>>n>>m;

    DSU gr(n);

    while(m--) {
        string s;
        cin>>s;
        if(s == "join") {
            int x,y;
            cin>>x>>y;
            gr.union_set(x,y);
        }
        else if(s == "add") {
            int x,v;
            cin>>x>>v;
            gr.add_experience(x,v);
        }
        else {
            int x;
            cin>>x;
            cout<<gr.find_set(x).second<<enl;
        }
    }

    return 0;
}