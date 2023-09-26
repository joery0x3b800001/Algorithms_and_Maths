// Three types of dsu
// -> Union by Rank
// -> Union by size
// -> Linking by index

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

// -------------------------------------------------

const int maxn = (int) 1e7;
int pr[maxn], w[maxn], ind[maxn];

int cntGet;
int get(int v) {
  ++cntGet;
  return v == pr[v] ? v : (pr[v] = get(pr[v]));
}

int TYPE;

void join(int s, int t) {
  s = get(s), t = get(t);
  if (s == t) {
    return;
  }
  switch(TYPE) {
    case 0:
      if (rnd(2)) {
        swap(s, t);
      }
      break;
    case 1:
      if (w[s] == w[t]) {
        ++w[s];
      } else {
        if (w[s] < w[t]) {
          swap(s, t);
        }
      }
      break;
    case 2:
      if (ind[s] < ind[t]) {
        swap(s, t);
      }
      break;
    default:
      assert(0);
  }

  pr[t] = s;
}

double solve(int n) {
  for (int i = 0; i < n; ++i) {
    pr[i] = i, w[i] = 0, ind[i] = i;
  }

  random_shuffle(ind, ind + n, rnd);
  
  cntGet = 0;
  for (int i = 1; i < n; ++i) {
    join(0, rnd(i / sqrt(5.0) + 1));
  }

  return (double) cntGet / n;
}

int main() {
  for (TYPE = 0; TYPE < 3; ++TYPE) {
    printf(!TYPE ? "RANDOM:\n" : (TYPE == 1 ? "RANKS:\n" : "INDEXES:\n"));
    for (int n = 1e4; n <= maxn; n *= 10) {
      printf("res[%.1e] = %.3f\n", (double) n, solve(n));
    }
  }
  return 0;
}