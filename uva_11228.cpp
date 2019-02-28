#include <bits/stdc++.h>
using namespace std;

vector<int> pr;
int n, r;

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

void solve(int data_set) {
  cin >> n >> r;
  vector<double> x(n), y(n);
  pr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<pair<double,pair<int,int> > > edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.push_back(make_pair(dist(x[i], y[i], x[j], y[j]), make_pair(i, j)));
    }
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; i++) {
    pr[i] = i;
  }
  double dist_low = 0, dist_high = 0;
  int states = 0;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    double d = edges[i].first;
    if (find(u) != find(v)) {
      combine(u, v);
      if (d > r) {
        states++;
        dist_high += d;
      } else {
        dist_low += d;
      }
    }
  }
  cout << "Case #" << data_set << ": " << states + 1 << ' ' << dist_low << ' ' << dist_high << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(0);
  srand(time(NULL));
  int qq;
  cin >> qq;
  int data_set = 1;
  while (qq--) {
    solve(data_set);
    data_set++;
  }
  return 0;
}