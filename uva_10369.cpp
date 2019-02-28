#include <bits/stdc++.h>
using namespace std;

vector<int> pr;

int find(int u) {
  pr[u] = (pr[u] == u ? u : find(pr[u]));
  return pr[u];
}

void combine(int u, int v) {
  u = find(u);
  v = find(v);
  if (rand() & 1) {
    pr[u] = v;
  } else {
    pr[v] = u;
  }
}

double dist(double xa, double ya, double xb, double yb) {
  return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

void solve() {
  int s, p;
  cin >> s >> p;
  vector<double> x(p), y(p);
  for (int i = 0; i < p; i++) {
    cin >> x[i] >> y[i];
  }
  vector<pair<double,pair<int,int> > > edges;
  for (int i = 0; i < p; i++) {
    for (int j = i + 1; j < p; j++) {
      edges.push_back(make_pair(dist(x[i], y[i], x[j], y[j]), make_pair(i, j)));
    }
  }
  sort(edges.begin(), edges.end());
  double ans = 0.0;
  int sz = 0;
  pr.resize(p);
  for (int i = 0; i < p; i++) {
    pr[i] = i;
  }
  for (int i = 0; i < p * (p - 1) / 2; i++) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    double d = edges[i].first;
    if (find(u) != find(v)) {
      sz++;
      combine(u, v);
      ans = max(ans, d);
    }
    if (sz == p - s) {
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(NULL));
  cout << fixed;
  cout.precision(2);
  int qq;
  cin >> qq;
  while (qq--) {
    solve();
  }
  return 0;
}