#include <bits/stdc++.h>
using namespace std;

int n, m, s;

bool valid(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

void solve() {
  string seq;
  vector<string> a;
  for (int i = 0; i < n; i++) {
    string u;
    cin >> u;
    a.push_back(u);
  }
  cin >> seq;
  const int dx[] = {0, 1, 0, -1};
  const int dy[] = {-1, 0, 1, 0};
  map<char,int> mp;
  mp['N'] = 0;
  mp['L'] = 1;
  mp['S'] = 2;
  mp['O'] = 3;
  int ans = 0;
  int cur_y, cur_x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp.find(a[i][j]) != mp.end()) {
        cur_y = i;
        cur_x = j;
      }
    }
  }
  int cur_dir = mp[a[cur_y][cur_x]];
  for (int i = 0; i < (int) seq.length(); i++) {
    if (seq[i] == 'D') {
      cur_dir++;
      cur_dir %= 4;
    } else if (seq[i] == 'E') {
      cur_dir--;
      if (cur_dir < 0) {
        cur_dir += 4;
      }
    } else {
      int next_y = cur_y + dy[cur_dir];
      int next_x = cur_x + dx[cur_dir];
      if (valid(next_y, next_x) && a[next_y][next_x] != '#') {
        cur_y = next_y;
        cur_x = next_x;
        ans += (a[cur_y][cur_x] == '*');
        a[cur_y][cur_x] = '.';
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n >> m >> s && n && m && s) {
    solve();
  }
  return 0;
}