#include <bits/stdc++.h>
using namespace std;

int n, m;
char land, water;
vector<string> a(25);

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

bool valid(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

int dfs(int y, int x) {
  a[y][x] = water;
  int ans = 1;
  for (int i = 0; i < 4; i++) {
    int next_y = y + dy[i];
    int next_x = x + dx[i];
    next_x %= m;
    if (next_x < 0) {
      next_x += m;
    }
    if (valid(next_y, next_x) && a[next_y][next_x] == land) {
      ans += dfs(next_y, next_x);
    }
  }
  return ans;
}

void solve() {
  cin.ignore();
  for (int i = 0; i < n; i++) {
    a[i].clear();
    getline(cin, a[i]);
  }
  int y, x;
  cin >> y >> x;
  land = a[y][x];
  int found_water = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != land) {
        water = a[i][j];
        found_water = 1;
      }
    }
  }
  if (!found_water) {
    cout << 0 << '\n';
    return;
  }
  int ans = 0;
  dfs(y, x);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == land) {
        ans = max(ans, dfs(i, j));
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m) {
    solve();
  }
  return 0;
}