#include <bits/stdc++.h>
using namespace std;

const int N = 123;
vector<vector<int> > g(N);
vector<int> dfs_time(N), dfs_low(N);
int root;
set<int> ans;

void dfs(int u, int pr, int cur_time, int *root_child) {
  dfs_time[u] = cur_time;
  dfs_low[u] = cur_time;
  for (int i = 0; i < (int) g[u].size(); i++) {
    int next = g[u][i];
    if (dfs_time[next] == -1) {
      if (u == root) {
        (*root_child)++;
      }
      dfs(next, u, cur_time + 1, root_child);
      if (dfs_low[next] >= dfs_time[u] && u != root) {
        ans.insert(u);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[next]);
    } else {
      if (next != pr) {
        dfs_low[u] = min(dfs_low[u], dfs_time[next]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    cin.ignore();
    string a;
    fill(g.begin(), g.end(), vector<int>());
    fill(dfs_time.begin(), dfs_time.end(), -1);
    while (true) {
      getline(cin, a);
      if (a == "0") {
        break;
      }
      stringstream ss(a);
      int u, v;
      ss >> u;
      u--;
      while (ss >> v) {
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
      if (dfs_time[i] == -1) {
        root = i;
        int child = 0;
        dfs(i, -1, 0, &child);
        if (child > 1) {
          ans.insert(i);
        }
      }
    }
    cout << ans.size() << '\n';
  }
  return 0;
}