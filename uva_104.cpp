#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
  	double dp[n][n][n + 1];
  	int par[n][n][n + 1];
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			for (int k = 2; k <= n; k++) {
  				dp[i][j][k] = 0.0;
  			}
  		}
  	}
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < n; j++) {
  			if (i == j) {
  				dp[i][j][1] = 1.0;
  				continue;
  			}
  			cin >> dp[i][j][1];
  			par[i][j][1] = i;
  		}
  	}
  	for (int step = 2; step <= n; step++) {
  		for (int k = 0; k < n; k++) {
  			for (int i = 0; i < n; i++) {
  				for (int j = 0; j < n; j++) {
  					if (dp[i][j][step] < dp[i][k][step - 1] * dp[k][j][1]) {
  						dp[i][j][step] = dp[i][k][step - 1] * dp[k][j][1];
  						par[i][j][step] = k;
  					}
  				}
  			}
  		}
  	}
		vector<int> path;
		for (int step = 1; step <= n; step++) {
			for (int i = 0; i < n; i++) {
				if (dp[i][i][step] > 1.01) {
  				int cur = i;
  				int stepp = step;
  				while (stepp > 0) {
  					path.push_back(cur);
  					cur = par[i][cur][stepp];
  					stepp--;
  				}
  				assert(cur == i);
  				path.push_back(cur);
  				reverse(path.begin(), path.end());
  				break;
  			}
			}
			if (path.size() != 0) {
				break;
			}
		}
		if (path.size() == 0) {
			cout << "no arbitrage sequence exists" << '\n';
		} else {
			for (int i = 0; i < (int) path.size(); i++) {
				if (i > 0) {
					cout << ' ';
				}
				cout << path[i] + 1;
			}
			cout << '\n';
		}
  }
  return 0;
}