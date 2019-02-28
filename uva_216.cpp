#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n;
double dist[N][N];
double dp[1 << N][N];
bool vis[1 << N][N];
double x[N], y[N];

double calc(int mask, int u) {
  if (vis[mask][u]) {
    return dp[mask][u];
  }
  assert(mask != (1 << n) - 1);
  vis[mask][u] = true;
  double ans = DBL_MAX;
  for (int i = 0; i < n; i++) {
    if (!(mask & (1 << i))) {
      ans = min(ans, calc(mask | (1 << i), i) + dist[u][i]);
    }
  }
  assert(ans != DBL_MAX);
  dp[mask][u] = ans;
  return ans;
}

int pop_count(int x) {
  int ans = 0;
  while (x) {
    ans += (x & 1);
    x >>= 1;
  }
  return ans;
}

vector<int> ans;
void trace(int mask, int u) {
  if (pop_count(mask) == n - 1) {
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) {
        ans.push_back(i);
      }
    }
    return;
  }
  double mn = DBL_MAX;
  int go_to;
  for (int i = 0; i < n; i++) {
    if (i != u && !(mask & (1 << i))) {
      if (dist[u][i] + calc(mask | (1 << i), i) < mn) {
        go_to = i;
        mn = dist[u][i] + calc(mask | (1 << i), i);
      }
    }
  }
  ans.push_back(go_to);
  trace(mask | (1 << go_to), go_to);
}

void solve(int cases) {
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) + 16.0;
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    vis[(1 << n) - 1][i] = true;
    dp[(1 << n) - 1][i] = 0.0;
  }
  double min_dist = DBL_MAX;
  for (int i = 0; i < n; i++) {
    min_dist = min(min_dist, calc((1 << i), i));
  }
  ans.clear();
  double mn = DBL_MAX;
  int start;
  for (int i = 0; i < n; i++) {
    if (calc((1 << i), i) < mn) {
      start = i;
      mn = calc((1 << i), i);
    }
  }
  ans.push_back(start);
  trace((1 << start), start);
  assert((int) ans.size() == n);
  cout << "**********************************************************" << '\n';
  cout << "Network #" << cases << '\n';
  for (int i = 0; i < n - 1; i++) {
    cout << "Cable requirement to connect (" << (int) x[ans[i]] << "," << (int) y[ans[i]] << ") " << "to (" << (int) x[ans[i + 1]] << "," << (int) y[ans[i + 1]] << ")";
    cout << " is " << dist[ans[i]][ans[i + 1]] << " feet.\n";
  }
  cout << "Number of feet of cable required is " << min_dist << ".\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);
  int cases = 1;
  while (cin >> n && n) {
    solve(cases);
    cases++;
  }
  return 0;
}