#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > mines;
vector<vector<int> > depth;
int n, m;

bool valid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < m) {
    return !mines[y][x];
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m && (n || m)) {
    mines.resize(n);
    fill(mines.begin(), mines.end(), vector<int>(m, 0));
    depth.resize(n);
    fill(depth.begin(), depth.end(), vector<int>(m, -1));
    int nr;
    cin >> nr;
    for (int i = 0; i < nr; i++) {
      int u;
      cin >> u;
      int deg;
      cin >> deg;
      while (deg--) {
        int v;
        cin >> v;
        mines[u][v] = 1;
      }
    }
    int sx, sy, fx, fy;
    cin >> sy >> sx >> fy >> fx;
    queue<pair<int,int> > q;
    q.push(make_pair(sy, sx));
    depth[sy][sx] = 0;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    while (!q.empty()) {
      int uy = q.front().first;
      int ux = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int vy = uy + dy[i];
        int vx = ux + dx[i];
        if (valid(vy, vx) && depth[vy][vx] == -1) {
          depth[vy][vx] = depth[uy][ux] + 1;
          q.push(make_pair(vy, vx));
        }
      }
    }
    cout << depth[fy][fx] << '\n';
  }
  return 0;
}