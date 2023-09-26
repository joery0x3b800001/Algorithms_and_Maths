// https://www.baeldung.com/cs/disjoint-set-union-data-structure

#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int countConnectedComponents() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int n, m; // n is the number of nodes, m is the number of edges
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionSets(u, v);
    }

    int numConnectedComponents = dsu.countConnectedComponents();
    cout << "Number of Connected Components: " << numConnectedComponents << endl;

    return 0;
}