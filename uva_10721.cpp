#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, m;
  while (cin >> n >> k >> m) {
    vector<vector<long long> > dp(n + 1, vector<long long>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int ii = 1; ii <= k; ii++) {
          if (i - j >= 0) {
            dp[i][ii] += dp[i - j][ii - 1];
          }
        }
      }
    }
    cout << dp[n][k] << '\n';
  }
  return 0;
}