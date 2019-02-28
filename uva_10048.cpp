#include <bits/stdc++.h>
using namespace std;

vector<int> pr;
vector<vector<pair<int,int> > > g;
int found;

int find(int u) {
  pr[u] = (pr[u] == u ? u : find(pr[u]));
  return pr[u];
}

void combine(int u, int v) {
  u = find(u);
  v = find(v);
  if (rand() & 1) {
    pr[u] = v;
  } else {
    pr[v] = u;
  }
}

int dfs(int u, int v, int par, int cur_max) {
  if (u == v) {
    found = 1;
    return cur_max;
  }
  int ans = 0;
  for (int i = 0; i < (int) g[u].size(); i++) {
    if (g[u][i].first != par) {
      ans = max(ans, dfs(g[u][i].first, v, u, max(cur_max, g[u][i].second)));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  int n, m, qq;
  for (int cases = 1; cin >> n >> m >> qq && (n || m || qq); cases++) {
    if (cases > 1) {
      cout << '\n';
    }
    vector<pair<int,pair<int,int> > > edges;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--; v--;
      edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    g.resize(n);
    pr.resize(n);
    fill(g.begin(), g.end(), vector<pair<int,int> >());
    for (int i = 0; i < n; i++) {
      pr[i] = i;
    }
    for (int i = 0; i < m; i++) {
      int u = edges[i].second.first;
      int v = edges[i].second.second;
      int w = edges[i].first;
      if (find(u) != find(v)) {
        combine(u, v);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
      }
    }
    cout << "Case #" << cases << '\n';
    while (qq--) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      found = 0;
      int ans = dfs(u, v, -1, 0);
      if (found) {
        cout << ans << '\n';
      } else {
        cout << "no path" << '\n';
      }
    }
  }
  return 0;
}