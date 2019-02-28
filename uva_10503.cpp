#include <bits/stdc++.h>
using namespace std;

int n, m;
int qwe, asd;
vector<pair<int,int> > v;
vector<int> vis(40);
int u[20];

bool coba(int x) {
  if (x == n + 1) {
    return (qwe == u[n]);
  }
  bool ok = false;
  for (int i = 0; i < m; i++) {
    if (!vis[i]) {
      if (v[i].first == u[x - 1]) {
        vis[i] = 1;
        u[x] = v[i].second;
        ok |= coba(x + 1);
        vis[i] = 0;
      }
      if (v[i].second == u[x - 1]) {
        vis[i] = 1;
        u[x] = v[i].first;
        ok |= coba(x + 1);
        vis[i] = 0;
      }
    }
  }
  return ok;
}

void solve() {
  cin >> qwe >> asd;
  u[0] = asd;
  cin >> qwe >> asd;
  v.clear();
  for (int i = 0; i < m; i++) {
    int vie, mini;
    cin >> vie >> mini;
    v.push_back(make_pair(vie, mini));
  }
  fill(vis.begin(), vis.end(), 0);
  cout << (coba(1) ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n && n) {
    cin >> m;
    solve();
  }
  return 0;
}