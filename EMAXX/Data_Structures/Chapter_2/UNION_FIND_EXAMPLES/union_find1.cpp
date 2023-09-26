#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

using namespace std;

namespace fastio {

constexpr int BSZ = 1 << 19;
char *ibuf, obuf[BSZ];
int outi, obufi;

void __attribute__((constructor)) _c() {
    struct stat sb; fstat(0, &sb);
    ibuf = (char *) mmap(0, sb.st_size, PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);
}

void flush() { write(1, obuf, obufi), obufi = 0; }

template <typename T>
void rd(T &x) {
    char c;
    for (x = *ibuf++ & 15; (c = *ibuf++) >= '0'; )
        x = x * 10 + (c & 15);
}

void rd(char &c) { c = *ibuf; ibuf += 2; }

void wt(char c) {
    obuf[obufi] = c;
    obuf[obufi + 1] = '\n';
    obufi += 2;
}

void __attribute__((destructor)) _d() { flush(); }

}

template <int N>
struct disjoint_set {
    int par[N + 1];

    disjoint_set() { memset(par, -1, sizeof(par)); }

    int find(int v) { return par[v] < 0 ? v : par[v] = find(par[v]); }

    void join(int u, int v) {
        if ((u = find(u)) != (v = find(v))) {
            if (par[u] > par[v]) par[v] += par[u], par[u] = v;
            else par[u] += par[v], par[v] = u;
        }
    }
};

disjoint_set<200000> ds;

using fastio::rd;
using fastio::wt;

int main() {
    int N, Q, u, v; char t;
    rd(N); rd(Q);
    while (Q--) {
        rd(t); rd(u); rd(v);
        if (t == '0') ds.join(u, v);
        else wt((ds.find(u) == ds.find(v)) | '0');
    }
    return 0;
}