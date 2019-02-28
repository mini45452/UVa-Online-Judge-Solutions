#include <bits/stdc++.h>
using namespace std;

const int M = 1e4;
const int N = 123;
const int inf = 1e4;

int m, n;
int p[N], f[N];
int dp[N][M];
bool vis[N][M];

int calc(int u, int w) {
  if (w > m + 200) {
    return -inf;
  }
  if (u == n) {
    if (w > m && w <= 2000) {
      return -inf;
    }
    return 0;
  }
  if (vis[u][w]) {
    return dp[u][w];
  }
  vis[u][w] = true;
  dp[u][w] = max(calc(u + 1, w), calc(u + 1, w + p[u]) + f[u]);
  return dp[u][w];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while (cin >> m >> n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> f[i];
    }
    cout << calc(0, 0) << '\n';
  }
  return 0;
}