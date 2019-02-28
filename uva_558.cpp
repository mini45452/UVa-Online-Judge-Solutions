#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
  	const int inf = 2e9;
  	int n, m;
  	cin >> n >> m;
  	vector<pair<int,pair<int,int> > > edges;
  	for (int i = 0; i < m; i++) {
  		int u, v, w;
  		cin >> u >> v >> w;
  		edges.push_back(make_pair(w, make_pair(u, v)));
  	}
  	vector<int> dist(n, inf);
  	dist[0] = 0;
  	for (int i = 0; i < n - 1; i++) {
  		for (int j = 0; j < m; j++) {
  			int w = edges[j].first;
  			int u = edges[j].second.first;
  			int v = edges[j].second.second;
  			dist[v] = min(dist[v], dist[u] + w);
  		}
  	}
  	int possible = 0;
  	for (int i = 0; i < m; i++) {
  		int u = edges[i].second.first;
  		int v = edges[i].second.second;
  		possible |= (dist[v] > dist[u] + edges[i].first);
  	}
  	if (!possible) {
  		cout << "not ";
  	}
  	cout << "possible\n";
  }
  return 0;
}