#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;

  ll x, y;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      x = i;
      y = n / i;
    }
  }

  cout << x + y - 2 << endl;
  return 0;
}
