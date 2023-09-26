// https://codeforces.com/problemset/problem/514/D
#include <bits/stdc++.h>
using namespace std;

template <class T, class F = function<T (const T&, const T&)>>
struct SparseTable {
  int n;
  vector<vector<T>> st;
  F func;

  SparseTable () {}

  SparseTable (const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int maxlg = 32 - __builtin_clz(n);
    st.resize(maxlg);
    st[0] = a;
    for (int j = 1; j < maxlg; j++) {
      st[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        st[j][i] = func(st[j-1][i], st[j-1][i + (1 << (j-1))]);
      }
    }
  }

  T get (int l, int r) const {
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

signed main() {
// #ifdef READ_FILE
//   freopen("input.txt", "r", stdin);
// #endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[j][i];
  }
  vector<SparseTable<int>> st(m);
  for (int i = 0; i < m; i++) {
    st[i] = SparseTable<int>(a[i], [&] (int px, int py) {
      return (px > py)? px: py;
    });
  }
  vector<int> res(m, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int lo = i;
    int hi = n - 1;
    int mid = lo + (hi - lo) / 2;
    while (lo <= hi) {
      long long cur = 0;
      for (int j = 0; j < m; j++) cur += st[j].get(i, mid);
      // debug(i, lo, hi ,mid, cur);
      if (cur > k) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
        if (ans < (mid - i + 1)) {
          ans = mid - i + 1;
          for (int j = 0; j < m; j++) res[j] = st[j].get(i, mid);
        }
      }
      mid = lo + (hi - lo) / 2;
    }
  }
  //cout << ans << "\n";
  for (auto x : res) cout << x << " ";
  cout << "\n";
  return 0;
}