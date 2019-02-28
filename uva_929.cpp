#include <bits/stdc++.h>
using namespace std;

bool valid(int y, int x, int n, int m) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

void solve() {
	int n, m;
	cin >> n >> m;
	const int inf = 1e9;
	vector<vector<int> > a(n, vector<int>(m));
	vector<vector<int> > dist(n, vector<int>(m, inf));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push(make_pair(-a[0][0], make_pair(0, 0)));
	dist[0][0] = a[0][0];
	const int dx[] = {0, 1, 0, -1};
	const int dy[] = {1, 0, -1, 0};
	while (!pq.empty()) {
		pair<int,pair<int,int> > u = pq.top();
		pq.pop();
		int d = -u.first;
		int uy = u.second.first;
		int ux = u.second.second;
		if (dist[uy][ux] < d) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int vy = uy + dy[i];
			int vx = ux + dx[i];
			if (valid(vy, vx, n, m)) {
				if (d + a[vy][vx] < dist[vy][vx]) {
					dist[vy][vx] = d + a[vy][vx];
					pq.push(make_pair(-dist[vy][vx], make_pair(vy, vx)));
				}
			}
		}
	}
	cout << dist[n - 1][m - 1] << '\n';
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