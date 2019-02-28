#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for (int i = 0; i < n; i++) {
    int ni;
    cin >> ni;
    while (ni--) {
      int v;
      cin >> v;
      g[i].push_back(v);
    }
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int start;
    cin >> start;
    if ((int) g[start].size() == 0) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> vis(n, 0);
    vector<int> days(n, 0);
    queue<pair<int,int> > q;
    vis[start] = 1;
    q.push(make_pair(start, 0));
    while (!q.empty()) {
      int u = q.front().first;
      int d = q.front().second;
      q.pop();
      if (d > 0) {
        days[d]++;
      }
      for (int i = 0; i < (int) g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) {
          vis[v] = 1;
          q.push(make_pair(v, d + 1));
        }
      }
    }
    int max_heard = 0;
    for (int i = 0; i < n; i++) {
      max_heard = max(max_heard, days[i]);
    }
    int ans_se;
    for (int i = 0; i < n; i++) {
      if (days[i] == max_heard) {
        ans_se = i;
        break;
      }
    }
    cout << max_heard << ' ' << ans_se << '\n';
  }
  return 0;
}