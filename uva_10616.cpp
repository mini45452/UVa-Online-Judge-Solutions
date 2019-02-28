#include <bits/stdc++.h>
using namespace std;

const int N = 210, M = 25;
int n, q, d, m;

int a[N];
long long dp[M][N][M];

int sub(int x, int y) {
  int ans = (x - y) % d;
  return (ans < 0 ? ans + d : ans);
}

long long solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[0][i][0] = 1;
  }
  dp[1][0][sub(a[0], 0)] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < n; j++) {
      for (int k = 0; k <= d - 1; k++) {
        dp[i][j][k] = dp[i][j - 1][k] + dp[i - 1][j - 1][sub(k, a[j])];
      }
    }
  }
  return dp[m][n - 1][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int set_i = 1; cin >> n >> q && n && q; set_i++) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << "SET " << set_i << ":\n";
    for (int i = 1; i <= q; i++) {
      cin >> d >> m;
      cout << "QUERY " << i << ": " << solve() << '\n';
    }
  }
  return 0;
}