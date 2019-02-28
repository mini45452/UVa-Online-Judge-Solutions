#include <bits/stdc++.h>
using namespace std;

int n, m, jump_y, jump_x;
vector<int> dy, dx;
vector<string> a(1234);
int visit[1005][1005];
int degree[1005][1005];

bool valid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < m) {
    return (a[y][x] != '#');
  }
  return false;
}

void dfs(int y, int x, int pr_y, int pr_x) {
  visit[y][x] = 1;
  for (int i = 0; i < (int) dy.size(); i++) {
    if (valid(y + dy[i], x + dx[i])) {
      if (!visit[y + dy[i]][x + dx[i]]) {
        dfs(y + dy[i], x + dx[i], y, x);
      }
      degree[y + dy[i]][x + dx[i]]++;
    }
  }
}

void solve(int cases) {
  cin >> n >> m >> jump_y >> jump_x;
  set<pair<int,int> > s;
  dy.clear();
  dx.clear();
  dy.push_back(jump_y);
  dx.push_back(jump_x);
  dy.push_back(jump_x);
  dx.push_back(jump_y);
  dy.push_back(-jump_y);
  dx.push_back(jump_x);
  dy.push_back(-jump_x);
  dx.push_back(jump_y);
  dy.push_back(-jump_y);
  dx.push_back(-jump_x);
  dy.push_back(-jump_x);
  dx.push_back(-jump_y);
  dy.push_back(jump_y);
  dx.push_back(-jump_x);
  dy.push_back(jump_x);
  dx.push_back(-jump_y);
  for (int i = 0; i < 8; i++) {
    s.insert(make_pair(dy[i], dx[i]));
  }
  dy.clear();
  dx.clear();
  for (set<pair<int,int> >::iterator it = s.begin(); it != s.end(); it++) {
    dy.push_back(it->first);
    dx.push_back(it->second);
  }
  for (int i = 0; i < n; i++) {
    a[i].clear();
    for (int j = 0; j < m; j++) {
      a[i].push_back('.');
    }
  }
  int waters;
  cin >> waters;
  while (waters--) {
    int x, y;
    cin >> y >> x;
    a[y][x] = '#';
  }
  memset(visit, 0, sizeof(visit));
  memset(degree, 0, sizeof(degree));
  dfs(0, 0, -1, -1);
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visit[i][j]) {
        odd += (degree[i][j] % 2 != 0);
        even += (degree[i][j] % 2 == 0);
      }
    }
  }
  cout << "Case " << cases << ": " << even << ' ' << odd << '\n';
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