vector<tuple<int, int, int>> history;
int get_par(int v) {
   if (v == parent[v]) return v;

   int p = get_par(parent[v]);
   history.emplace_back(1, v, parent[v]);  // old value
   parent[v] = p;
   return p;
}

void unite(int u, int v) {
   u = get_par(u)
   v = get_par(v)
   if (u == v) return;
   if (rank_[u] > rank_[v]) swap(u, v);

   history.emplace_back(1, u, parent[u]);
   parent[u] = v;
   history.emplace_back(2, v, rank_[v]);
   rank_[v] += rank_[u];
}

// only one rollback, doesn't mean one unite or one get_par undo
// usually I save history.size() somewhere when I need it and then do rollbacks until that moment
void rollback() {
   auto [type, ind, val] = history.back();
   history.pop_back();
   if (type == 1) {
     parent[ind] = val;
   } else {
     rank_[ind] = val;
   }
}