// Question - 2(version-3)
#include <iostream>
#include <vector>
using namespace std;

struct dsu {
    dsu(int v) {
        parent.resize(v + 1); // Resize to v+1 to accommodate 1-based indexing
        max_elem.resize(v + 1); // Resize to v+1
        min_elem.resize(v + 1); // Resize to v+1
        size_.resize(v + 1, 1); // Resize to v+1 and initialize with 1

        for (int i = 1; i <= v; ++i) {
            parent[i] = i;
            min_elem[i] = i;
            max_elem[i] = i;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size_[a] < size_[b])
                swap(a, b);
            parent[b] = a;
            size_[a] += size_[b];
            min_elem[a] = min(min_elem[a], min_elem[b]);
            max_elem[a] = max(max_elem[a], max_elem[b]);
        }
    }

    void get(int v) {
        int root = find_set(v);
        cout << min_elem[root] << " " << max_elem[root] << " " << size_[root] << '\n';
    }

private:
    vector<int> parent, min_elem, max_elem, size_;
};

int main() {
    int n, m;
    cin >> n >> m;

    dsu d(n);

    for (int i = 0; i < m; i++) {
        string query;
        int u, v;
        cin >> query;
        if (query == "union") {
            cin >> u >> v;
            d.union_sets(u, v);
        } else if (query == "get") {
            cin >> v;
            d.get(v);
        }
    }
    return 0;
}