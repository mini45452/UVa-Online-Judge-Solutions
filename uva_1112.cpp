#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, e, t, m;
	cin >> n >> e >> t >> m;
	e--;
	vector<vector<pair<int,int> > > g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[v].push_back(make_pair(u, w));
	}
	priority_queue<pair<int,int> > pq;
	vector<int> dist(n, -1);
	pq.push(make_pair(0, e));
	dist[e] = 0;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (dist[u] < d) {
			continue;
		}
		for (int i = 0; i < (int) g[u].size(); i++) {
			int v = g[u][i].first;
			int w = g[u][i].second;
			if (d + w < dist[v] || dist[v] == -1) {
				dist[v] = d + w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (dist[i] != -1 && dist[i] <= t);
	}
	cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  int cases = 0;
  while (qq--) {
  	if (cases > 0) {
  		cout << '\n';
  	}
  	solve();
  	cases++;
  }
  return 0;
}