#include <bits/stdc++.h>
using namespace std;

vector<string> all;
set<string> s;
string cur_a = "!!!!!";
string cur_b = "!!!!!";
vector<string> a(6), b(6);

void recur(int x) {
  if (x == 5) {
    all.push_back(cur_a);
    s.insert(cur_b);
    return;
  }
  for (int i = 0; i < 6; i++) {
    cur_a[x] = a[i][x];
    cur_b[x] = b[i][x];
    recur(x + 1);
  }
}

void solve() {
  int k;
  cin >> k;
  all.clear();
  s.clear();
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 6; i++) {
    cin >> b[i];
  }
  recur(0);
  int u = 0;
  all.erase(unique(all.begin(), all.end()), all.end());
  sort(all.begin(), all.end());
  for (int i = 0; i < (all).size(); i++) {
    if (s.find(all[i]) != s.end()) {
      u++;
      if (u == k) {
        cout << all[i] << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
    solve();
  }
  return 0;
}