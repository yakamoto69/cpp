#include "common.h"

class SemieulerianPath {
private:
  int n;
  V<V<PI>> g;
  V<bool> used;
  VI ix;

public:
  VI path;

  SemieulerianPath(int n, VI &from, VI &to): n(n), g(n), used(from.size()), ix(n) {
    for (int i = 0; i < from.size(); ++i) {
      int v = from[i], u = to[i];
      g[v].emplace_back(u, i);
      g[u].emplace_back(v, i);
    }
  }

  bool make() {
    int s = -1;
    int odds = 0;
    for (int i = 0; i < n; ++i) {
      if (s == -1 && !g[i].empty()) s = i;
      if (g[i].size()&1) odds++, s = i;
    }

    function<void(int)> dfs = [&](int v) {
      while(ix[v] < g[v].size()) {
        int i = ix[v]++;
        if (!used[g[v][i]._2]) {
          used[g[v][i]._2] = true;
          dfs(g[v][i]._1);
        }
      }
      path.push_back(v);
    };

    if (odds != 0 && odds != 2) return false;

    dfs(s);

    return path.size() == used.size() + 1; // used.size() == edges.size()
  }
};