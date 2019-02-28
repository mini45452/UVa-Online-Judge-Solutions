#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int SIEVE_SZ = (int) sqrt((unsigned int) (1 << 31) - 1) + 10;
  int n;
  vector<int> prime(SIEVE_SZ, 1), primes;
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i * i <= SIEVE_SZ; i++) {
    if (prime[i]) {
      for (int j = i + i; j < SIEVE_SZ; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i < SIEVE_SZ; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  while (cin >> n && n) {
    int N = n;
    int pf_idx = 0;
    int pf = primes[0];
    vector<int> ans;
    if (n < 0) {
      ans.push_back(-1);
      n *= -1;
    }
    while (pf * pf <= n) {
      while (n % pf == 0) {
        ans.push_back(pf);
        n /= pf;
      }
      pf_idx++;
      if (pf_idx >= (int) primes.size()) {
        break;
      }
      pf = primes[pf_idx];
    }
    if (n != 1) {
      ans.push_back(n);
    }
    cout << N << " = ";
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " x ";
      }
      cout << ans[i];
    }
    cout << '\n';
  }
  return 0;
}