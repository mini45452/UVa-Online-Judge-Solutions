#include <bits/stdc++.h>
using namespace std;

const int N = 222;

int n, m;
vector<vector<int> > g(N);
vector<int> color(N);
int ans;

void dfs(int u, int col) {
  color[u] = col;
  for (int i = 0; i < (int) g[u].size(); i++) {
    int next = g[u][i];
    if (color[next] == -1) {
      dfs(next, col ^ 1);
    } else {
      if (color[next] == color[u]) {
        ans = 0;
      }
    }
  }
}

void solve() {
  fill(g.begin(), g.end(), vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  fill(color.begin(), color.end(), -1);
  ans = 1;
  dfs(0, 0);
  if (!ans) cout << "NOT ";
  cout << "BICOLORABLE.\n";
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