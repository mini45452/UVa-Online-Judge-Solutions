#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  for (int cases = 1; cases <= qq; cases++) {
  	int n, m;
  	cin >> n >> m;
  	const int inf = 1e9;
  	vector<vector<int> > dist(n, vector<int>(n, inf));
  	for (int i = 0; i < n; i++) {
  		dist[i][i] = 0;
  	}
  	for (int i = 0; i < m; i++) {
  		int u, v;
  		cin >> u >> v;
  		dist[u][v] = 1;
  		dist[v][u] = 1;
  	}
  	for (int k = 0; k < n; k++) {
  		for (int i = 0; i < n; i++) {
  			for (int j = 0; j < n; j++) {
  				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  			}
  		}
  	}
  	int s, e;
  	cin >> s >> e;
  	int ans = 0;
  	for (int i = 0; i < n; i++) {
  		ans = max(ans, dist[s][i] + dist[i][e]);
  	}
  	cout << "Case " << cases << ": " << ans << '\n';
  }
  return 0;
}