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
  	int ans = 2;
  	int sum = a[0];
  	for (int i = 1; i < n - 1; i++) {
  		if (sum + a[i] < a[i + 1]) {
  			ans++;
  			sum += a[i];
  		}
  	}
  	cout << ans << '\n';
  }
  return 0;
}