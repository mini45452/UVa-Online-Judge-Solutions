#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a(105);

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool valid(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

int dfs(int y, int x) {
  int ans = (a[y][x] == 'x');
  a[y][x] = '.';
  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];
    if (valid(next_y, next_x) && a[next_y][next_x] != '.') {
      ans += dfs(next_y, next_x);
    }
  }
  return ans;
}

void solve(int cases) {
  cin >> n;
  m = n;
  for (int i = 0; i < n; i++) {
    a[i].clear();
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '.') {
        ans += (dfs(i, j) > 0);
      }
    }
  }
  cout << "Case " << cases << ": " << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  int cases = 1;
  while (qq--) {
    solve(cases);
    cases++;
  }
  return 0;
}