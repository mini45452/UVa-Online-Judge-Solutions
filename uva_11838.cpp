#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > g;
vector<int> reach_time;
vector<int> low_link;
vector<int> in_stack;
stack<int> stk;
int ans;

void dfs(int u, int counter) {
  reach_time[u] = counter;
  low_link[u] = counter;
  in_stack[u] = 1;
  stk.push(u);
  for (int i = 0; i < (int) g[u].size(); i++) {
    int v = g[u][i];
    if (!reach_time[v]) {
      dfs(v, counter + 1);
    }
    if (in_stack[v]) {
      low_link[u] = min(low_link[u], low_link[v]);
    }
  }
  if (low_link[u] == reach_time[u]) {
    ans++;
    while (true) {
      int t = stk.top();
      stk.pop();
      in_stack[t] = 0;
      if (t == u) {
        break;
      }
    }
  }
}

void solve(int data_set) {
  g.resize(n);
  fill(g.begin(), g.end(), vector<int>());
  map<string,int> mp;
  map<int,string> mpi;
  for (int i = 0; i < m; i++) {
    string a, b;
    int c;
    cin >> a >> b >> c;
    if (mp.find(a) == mp.end()) {
      mp[a] = 0;
      mp[a] = (int) mp.size() - 1;
      mpi[mp[a]] = a;
    }
    if (mp.find(b) == mp.end()) {
      mp[b] = 0;
      mp[b] = (int) mp.size() - 1;
      mpi[mp[b]] = b;
    }
    g[mp[a]].push_back(mp[b]);
    if (c == 2) {
      g[mp[b]].push_back(mp[a]);
    }
  }
  reach_time.resize(n);
  low_link.resize(n);
  in_stack.resize(n);
  fill(in_stack.begin(), in_stack.end(), 0);
  fill(reach_time.begin(), reach_time.end(), 0);
  assert(stk.empty());
  ans = 0;
  for (int i = 0; i < n; i++) {
    if (!reach_time[i]) {
      dfs(i, 1);
    }
  }
  cout << (ans == 1) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int data_set = 1; cin >> n >> m && (n || m); data_set++) {
    solve(data_set);
  }
  return 0;
}