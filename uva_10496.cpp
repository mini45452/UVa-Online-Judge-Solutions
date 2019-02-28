#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int inf = 1e9;
int x[N], y[N];
bool vis[1 << N][N];
int dp[1 << N][N];
int n;

int get_dist(int xa, int ya, int xb, int yb) {
  return abs(xa - xb) + abs(ya - yb);
}

int calc(int mask, int u) {
  if (vis[mask][u]) {
    return dp[mask][u];
  }
  vis[mask][u] = true;
  int ans = inf;
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      ans = min(ans, calc((mask | (1 << i)), i) + get_dist(x[u], y[u], x[i], y[i]));
    }
  }
  dp[mask][u] = ans;
  return ans;
}

void solve() {
  int lol, wkwk;
  cin >> lol >> wkwk;
  cin >> x[0] >> y[0];
  cin >> n;
  n++;
  for (int i = 1; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i < n; i++) {
    vis[(1 << n) - 1][i] = true;
    dp[(1 << n) - 1][i] = get_dist(x[i], y[i], x[0], y[0]);
  }
  cout << "The shortest path has length " << calc(1, 0) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
    solve();
  }
  return 0;
}