#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int w[15][N];
int dp[15][N];

void solve() {
  int x;
  cin >> x;
  x /= 100;
  const int inf = 1e7;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < x; j++) {
      dp[i][j] = inf;
    }
  }
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < x; j++) {
      cin >> w[i][j];
      w[i][j] = -w[i][j];
    }
  }
  dp[0][0] = 0;
  for (int j = 1; j < 10; j++) {
    dp[j][j] = dp[j - 1][j - 1] + w[j - 1][j - 1] + 60;
  }
  for (int j = 1; j < x; j++) {
    for (int i = 0, jj = j; i < 10 && jj < x; i++, jj++) {
      int choice_1 = (i == 0 ? inf : dp[i - 1][jj - 1] + w[i - 1][jj - 1] + 60);
      int choice_2 = dp[i][jj - 1] + w[i][jj - 1] + 30;
      int choice_3 = dp[i + 1][jj - 1] + w[i + 1][jj - 1] + 20;
      dp[i][jj] = min(min(choice_1, choice_2), choice_3);
    }
  }
  cout << min(dp[0][x - 1] + w[0][x - 1] + 30, dp[1][x - 1] + w[1][x - 1] + 20) << "\n\n";
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