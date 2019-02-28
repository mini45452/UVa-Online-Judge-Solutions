#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 1e6 + 10;
  vector<int> prime(N, 1);
  vector<int> primes;
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  int qq;
  cin >> qq;
  while (qq--) {
    int l, r;
    cin >> l >> r;
    int ans = -1;
    int ans_i;
    for (int j = l; j <= r; j++) {
      int cur_div = 1;
      int pf_idx = 0;
      int pf = primes[0];
      int n = j;
      while (pf * pf <= n) {
        int cur_p = 1;
        while (n % pf == 0) {
          n /= pf;
          cur_p++;
        }
        pf_idx++;
        if (pf_idx >= (int) primes.size()) {
          break;
        }
        pf = primes[pf_idx];
        cur_div *= cur_p;
      }
      if (n != 1) {
        cur_div *= 2;
      }
      if (cur_div > ans) {
        ans = cur_div;
        ans_i = j;
      }
    }
    cout << "Between " << l << " and " << r << ", " << ans_i << " has a maximum of " << ans << " divisors." << '\n';
  }
  return 0;
}