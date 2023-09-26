#include <iostream>
#include <array>
using namespace std;

const int MAX_N = 1e5 + 5;

struct dsu {
    int l, r, c;
    dsu() {}
    dsu(int ll, int rr, int cc) : l{ll}, r{rr}, c{cc} {}
};

array<dsu, MAX_N> query;

int parent[MAX_N], result[MAX_N], end_[MAX_N], rank_[MAX_N];

void make_set(int v) {
    parent[v] = v;
    end_[v] = v;
    rank_[v] = 0;
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
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        end_[a] = max(end_[a], end_[b]);
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

void paintSubarraysOffline(int L, int m) {
    for (int i = 0; i <= L; i++) {
        make_set(i);
    }

    for (int i = m - 1; i >= 0; i--) {
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;
        int v = find_set(l);

        while (v <= r) {
            result[v] = c;
            int next = end_[v] + 1;
            union_sets(v, next);
            v = find_set(next);
        }
    }
}

int main() {
    int L = 10;
    int m = 5;

    query = {
        dsu(1, 5, 1),
        dsu(2, 8, 2),
        dsu(4, 6, 3),
        dsu(7, 9, 4),
        dsu(3, 7, 5)
    };

    paintSubarraysOffline(L, m);

    for (int i = 1; i <= L; i++) {
        cout << "Element " << i << " : " << result[i] << endl;
    }
 }