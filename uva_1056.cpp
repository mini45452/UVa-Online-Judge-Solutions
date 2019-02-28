#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, nw = 1;
  while (cin >> n >> m && (n || m)) {
  	map<string,int> mp;
  	const int inf = 1e9;
  	vector<vector<int> > dist(n, vector<int>(n, inf));
  	for (int i = 0; i < n; i++) {
  		dist[i][i] = 0;
  	}
  	for (int i = 0; i < m; i++) {
  		string a, b;
  		cin >> a >> b;
  		if (mp.find(a) == mp.end()) {
  			mp[a] = 0;
  			mp[a] = (int) mp.size() - 1;
  		}
  		if (mp.find(b) == mp.end()) {
  			mp[b] = 0;
  			mp[b] = (int) mp.size() - 1;
  		}
  		dist[mp[a]][mp[b]] = 1;
  		dist[mp[b]][mp[a]] = 1;
  	}
  	if ((int) mp.size() != n) {
  		cout << "Network " << nw << ": DISCONNECTED" << "\n\n";
  		nw++;
  		continue;
  	}
  	for (int k = 0; k < n; k++) {
  		for (int i = 0; i < n; i++) {
  			for (int j = 0; j < n; j++) {
  				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  			}
  		}
  	}
  	int ans = 0;
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			ans = max(ans, dist[i][j]);
  		}
  	}
  	cout << "Network " << nw << ": ";
  	if (ans == inf) {
  		cout << "DISCONNECTED" << '\n';
  	} else {
  		cout << ans << '\n';
  	}
  	cout << '\n';
  	nw++;
  }
  return 0;
}