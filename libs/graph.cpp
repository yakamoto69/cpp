#include "common.h"

/**
 * 隣接行列使うようになっているので、隣接リストバージョンが欲しい
 */
bool topological_sort(const V<VI> &g, VI &res) {
  VI deg(g.size(), 0);
  for (auto & v : g) {
    for (int j = 0; j < v.size(); ++j) {
      if (v[j]) deg[j]++;
    }
  }

  std::deque<int> q;
  for (int i = 0; i < g.size(); ++i) {
    if (deg[i] == 0) q.push_back(i);
  }

  while(!q.empty()) {
    int v = q.front();
    q.pop_front();
    res.push_back(v);

    for (int u = 0; u < g[v].size(); ++u) {
      if (g[v][u]) {
        deg[u]--;
        if (deg[u] == 0) q.push_back(u);
      }
    }
  }

  bool ok = true;
  for (const auto &d : deg) ok &= d == 0;
  return ok;
}

/*
 * g: (node, cost)形式の隣接リスト
 */
int dijkstra(const V<V<PI>> &g, int src, int dst) {
  using E = PI; // (cost, node)
  int INF = (int)1e9;
  int n = (int)g.size();
  VI d(n, INF);
  std::priority_queue<E, V<E>, std::greater<>> q;
  q.push(E(0, src));
  d[src] = 0;

  while(!q.empty()) {
    auto e = q.top();
    q.pop();
    int v = e._2;
    int c = e._1;

    if (d[v] == c) {
      d[v] = c;
      for (const auto &u : g[v]) {
        if (d[u._1] > c + u._2) {
          q.push(E(c + u._2, u._1));
          d[u._1] = c + u._2;
        }
      }
    }
  }

  return d[dst] == INF ? -1 : d[dst];
}

/*
 * 最大でK回遷移する
 */
int kth_bellman_ford(V<V<PI>> &g, int src, int dst, int K) {
  int INF = (int)1e9;
  int n = (int)g.size();
  V<VI> d(K + 1, VI(n, INF));
  d[0][src] = 0;
  for (int k = 0; k < K; ++k) {
    for (int v = 0; v < n; ++v) {
      for (const auto &u : g[v]) {
        d[k + 1][u._1] = min(d[k + 1][u._1], d[k][v] + u._2);
      }
    }
  }

  int res = INF;
  for (int k = 1; k <= K; ++k) res = min(res, d[k][dst]);
  return res == INF ? -1 : res;
}

class semieulerian_path {
private:
  int n;
  V<V<PI>> g;
  V<bool> used;
  VI ix;

public:
  VI path;

  semieulerian_path(int n, VI &from, VI &to): n(n), g(n), used(from.size()), ix(n) {
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