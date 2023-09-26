// Question - 2(version-1)
// Fastest and less memory
#include <iostream>
#include <vector>
#pragma GCC optimize("O3")
using namespace std;
 
struct dsu {
    vector<int> parent, min_elem, max_elem, size_;
 
    dsu(int v) {
        parent.resize(v);
        min_elem.resize(v);
        max_elem.resize(v);
        size_.resize(v, 1);
        for (int i = 0; i < v; i++) {
            parent[i] = i;
            min_elem[i] = i + 1;
            max_elem[i] = i + 1;
        }
    }
 
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
 
    void union_sets(int a, int b) {
        a--; b--;
        a = find_set(a);
        b = find_set(b);
 
        if (a != b) {
            parent[b] = a;
            size_[a] += size_[b];
            min_elem[a] = min(min_elem[a], min_elem[b]);
            max_elem[a] = max(max_elem[a], max_elem[b]);
        }
    }
 
    void get_set_info(int v) {
        v--;
        int root = find_set(v);
        cout << min_elem[root] << " " << max_elem[root] << " " << size_[root] << '\n';
    }
};
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
 
    dsu d(n);
 
    for (int i = 0; i < m; i++) {
       string query; int u, v;
       cin >> query >> u;
       if (query == "union") {
          cin >> v;
          d.union_sets(u, v);
       } else if (query == "get") {
          d.get_set_info(u);
       }
    }
    return 0;
}