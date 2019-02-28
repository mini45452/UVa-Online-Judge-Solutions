#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  while (cin >> m && m) {
  	const int N = 26;
  	const int inf = 1e9;
  	vector<vector<int> > g_me(N, vector<int>(N, inf));
  	vector<vector<int> > g_prof(N, vector<int>(N, inf));
  	for (int i = 0; i < N; i++) {
  		g_me[i][i] = 0;
  		g_prof[i][i] = 0;
  	}
  	while (m--) {
  		char age, dir, uu, vv;
	  	int w;
	  	cin >> age >> dir >> uu >> vv >> w;
	  	int u = uu - 'A';
	  	int v = vv - 'A';
	  	if (u == v) {
	  		w = 0;
	  	}
	  	if (age == 'Y') {
	  		g_me[u][v] = w;
	  		if (dir == 'B') {
	  			g_me[v][u] = w;
	  		}
	  	} else {
	  		g_prof[u][v] = w;
	  		if (dir == 'B') {
	  			g_prof[v][u] = w;
	  		}
	  	}
  	}
  	char mpp, ppp;
  	cin >> mpp >> ppp;
  	int mp = mpp - 'A';
  	int pp = ppp - 'A';
  	for (int k = 0; k < N; k++) {
  		for (int i = 0; i < N; i++) {
  			for (int j = 0; j < N; j++) {
  				g_me[i][j] = min(g_me[i][j], g_me[i][k] + g_me[k][j]);
  				g_prof[i][j] = min(g_prof[i][j], g_prof[i][k] + g_prof[k][j]);
  			}
  		}
  	}
  	int ans_cost = inf;
  	for (int i = 0; i < N; i++) {
  		ans_cost = min(ans_cost, g_me[mp][i] + g_prof[pp][i]);
  	}
  	if (ans_cost == inf) {
  		cout << "You will never meet." << '\n';
  		continue;
  	}
  	cout << ans_cost;
  	for (int i = 0; i < N; i++) {
  		if (g_me[mp][i] + g_prof[pp][i] == ans_cost) {
  			cout << ' ' << (char) (i + 'A');
  		}
  	}
  	cout << '\n';
  }
  return 0;
}