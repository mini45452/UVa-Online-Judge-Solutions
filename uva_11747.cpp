#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> pr;

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

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  int n, m;
  while (cin >> n >> m && (n || m)) {
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i] = i;
    }
    vector<pair<int,pair<int,int> > > edges;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    vector<int> pick(m, 1);
    int cycle = 0;
    for (int i = 0; i < m; i++) {
      int u = edges[i].second.first;
      int v = edges[i].second.second;
      int w = edges[i].first;
      if (find(u) != find(v)) {
        combine(u, v);
        pick[i] = 0;
      } else {
        cycle = 1;
      }
    }
    int fi = 1;
    if (cycle) {
      for (int i = 0; i < m; i++) {
        if (pick[i]) {
          if (!fi) {
            cout << ' ';
          }
          cout << edges[i].first;
          fi = 0;
        }
      }
    } else {
      cout << "forest";
    }
    cout << '\n';
  }
  return 0;
}