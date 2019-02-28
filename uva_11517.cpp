#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int dp[N];

void solve() {
  const int inf = 1e9;
  for (int i = 0; i < N; i++) {
    dp[i] = inf;
  }
  dp[0] = 0;
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u;
    cin >> u;
    for (int i = N - 1; i >= u; i--) {
      dp[i] = min(dp[i], dp[i - u] + 1);
    }
  }
  for (int i = n; i < N; i++) {
    if (dp[i] != inf) {
      cout << i << ' ' << dp[i] << '\n';
      return;
    }
  }
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