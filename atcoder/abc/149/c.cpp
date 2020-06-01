#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  cin >> x;

  for (int n = x; n <= 1e6; ++n) {
    bool isPrime = true;
    for (ll i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime && n >= x) {
      cout << n << endl;
      return 0;
    }
  }
  return 0;
}
