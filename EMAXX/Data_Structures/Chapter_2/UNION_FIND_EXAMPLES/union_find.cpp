//fastio of lydxn
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
using namespace fastio;
typedef unsigned int uint;
const int maxn=2e5+5;
static int parent[maxn];
static int_fast8_t lp[maxn];
int32_t main()
{
    int n,q;
    rd(n);rd(q);
    while(q--)
    {
        int typ,u,v;
        rd(typ);rd(u);rd(v);
        ++u;++v;
        if(typ==0)
        {
            int u1=u;
            while(parent[u]) u=parent[u];
            int v1=v;
            while(parent[v]) v=parent[v];
            int hu;
            while(u1!=u) {hu=parent[u1];parent[u1]=u;u1=parent[u1];}
            int hv;
            while(v1!=v) {hv=parent[v1];parent[v1]=v;v1=parent[v1];}
            if(u==v) continue;
            if(lp[u]>lp[v]) parent[v]=u;
            else if(lp[u]==lp[v]) {parent[v]=u;++lp[u];}
            else parent[u]=v;
        }
        else
        {
            int u1=u;
            while(parent[u]) u=parent[u];
            int v1=v;
            while(parent[v]) v=parent[v];
            int hu;
            while(u1!=u) {hu=parent[u1];parent[u1]=u;u1=parent[u1];}
            int hv;
            while(v1!=v) {hv=parent[v1];parent[v1]=v;v1=parent[v1];}
            if(u==v) wt('1');
            else wt('0');
        }
    }
    return 0;
}