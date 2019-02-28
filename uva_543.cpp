#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 1e6 + 10;
  vector<int> primes, prime(N, 1);
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i + i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  int n;
  while (cin >> n && n) {
    int a = -1, b = -1;;
    for (int i = 0; i < (int) primes.size(); i++) {
      if (n - primes[i] > 0 && prime[n - primes[i]]) {
        a = primes[i];
        b = n - primes[i];
        break;
      }
    }
    if (a == -1 && b == -1) {
      cout << "Goldbach's conjecture is wrong." << '\n';
    } else {
      cout << n << " = " << a << " + " << b << '\n';
    }
  }
  return 0;
}