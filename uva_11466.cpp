#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  const int SIEVE_SZ = 1e7 + 100;
  bitset<SIEVE_SZ> bs;
  bs.set();
  for (int i = 2; i * i <= SIEVE_SZ; i++) {
    if (bs.test(i)) {
      for (int j = i * i; j < SIEVE_SZ; j += i) {
        bs.reset(j);
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i < SIEVE_SZ; i++) {
    if (bs.test(i)) {
      primes.push_back(i);
    }
  }
  while (cin >> n && n) {
    n = max(n, -n);
    int pf_idx = 0;
    int pf = primes[0];
    vector<long long> factors;
    while (pf * pf <= n) {
      while (n % pf == 0) {
        factors.push_back(pf);
        n /= pf;
      }
      pf_idx++;
      if (pf_idx >= (int) primes.size()) {
        break;
      }
      pf = primes[pf_idx];
    }
    if (n != 1) {
      factors.push_back(n);
    }
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    if (factors.size() > 1) {
      cout << factors[factors.size() - 1] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}