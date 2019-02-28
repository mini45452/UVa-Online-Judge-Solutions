#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        factors.push_back(i);
        factors.push_back(n / i);
      }
    }
    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    int sz = (int) factors.size();
    int ans = 0;
    for (int i = 0; i < sz; i++) {
      for (int j = i; j < sz; j++) {
        int u = factors[i];
        int v = factors[j];
        if (1LL * u * (v / __gcd(u, v)) == 1LL * n) {
          ans++;
        }
      }
    }
    cout << n << ' ' << ans << '\n';
  }
  return 0;
}