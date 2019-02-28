#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int qq;
  cin >> qq;
  while (qq--) {
  	int n;
  	cin >> n;
  	vector<int> a(n);
  	for (int i = 0; i < n; i++) {
  		cin >> a[i];
  	}
  	if (n <= 1) {
  		cout << n << '\n';
  		continue;
  	}
  	reverse(a.begin(), a.end());
  	vector<int> lis(n, 1), lds(n, 1);
  	for (int j = 1; j < n; j++) {
  		for (int i = 0; i < j; i++) {
  			if (a[j] < a[i]) {
  				lds[j] = max(lds[j], lds[i] + 1);
  			}
  			if (a[j] > a[i]) {
  				lis[j] = max(lis[j], lis[i] + 1);
  			}
  		}
  	}
  	int ans = 0;
  	for (int i = 0; i < n; i++) {
  		ans = max(ans, lis[i] + lds[i] - 1);
  	}
  	cout << ans << '\n';
  }
  return 0;
}