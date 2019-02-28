#include <bits/stdc++.h>
using namespace std;

const int md = 1000000;

void add(int &a, int b) {
  a += b;
  if (a > md) a -= md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k && n && k) {
    vector<vector<int> > dp(k + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j <= n; j++) {
        for (int ii = 0; ii + j <= n; ii++) {
          add(dp[i][ii + j], dp[i - 1][ii]);
        }
      }
    }
    cout << dp[k][n] << '\n';
  }
  return 0;
}