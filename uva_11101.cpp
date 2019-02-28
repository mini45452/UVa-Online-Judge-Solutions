#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

bool valid(int y, int x) {
  return y >= 0 && x >= 0 && y < N && x < N;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n && n) {
    vector<vector<int> > depth(N, vector<int>(N, -1));
    queue<pair<int,int> > q;
    for (int i = 0; i < n; i++) {
      int y, x;
      cin >> y >> x;
      depth[y][x] = 0;
      q.push(make_pair(y, x));
    }
    vector<vector<int> > finish(N, vector<int>(N, 0));
    cin >> n;
    for (int i = 0; i < n; i++) {
      int y, x;
      cin >> y >> x;
      finish[y][x] = 1;
    }
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    const int inf = 2e9;
    int ans = inf;
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
          if (finish[vy][vx]) {
            ans = min(ans, depth[vy][vx]);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}