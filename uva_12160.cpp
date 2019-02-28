#include <bits/stdc++.h>
using namespace std;

int to_int(string a) {
  int d1 = a[3] - '0';
  int d2 = a[2] - '0';
  int d3 = a[1] - '0';
  int d4 = a[0] - '0';
  return d1 + d2 * 10 + d3 * 100 + d4 * 1000;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int u, v, n;
  int cases = 1;
  string uu, vv;
  while (cin >> uu >> vv >> n && (uu != "0" || vv != "0" || n)) {
    u = to_int(uu);
    v = to_int(vv);
    vector<int> moves;
    for (int i = 0; i < n; i++) {
      string a;
      cin >> a;
      moves.push_back(to_int(a));
    }
    vector<int> depth(10000, -1);
    queue<int> q;
    depth[u] = 0;
    q.push(u);
    int found = 0;
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      for (int i = 0; i < (int) moves.size(); i++) {
        int next = (t + moves[i]) % 10000;
        if (depth[next] == -1) {
          depth[next] = depth[t] + 1;
          q.push(next);
          found |= (next == v);
        }
      }
    }
    cout << "Case " << cases << ": ";
    if (found) {
      cout << depth[v];
    } else {
      cout << "Permanently Locked";
    }
    cout << '\n';
    cases++;
  }
  return 0;
}