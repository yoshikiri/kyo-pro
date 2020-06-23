#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll l, r;
  cin >> l >> r;

  const int mod = 2019;
  ll ans = mod;
  r = min(r, l + mod);
  for (ll i = l; i <= r; ++i) {
    for (ll j = i + 1; j <= r; ++j) {
      ans = min(ans, i * j % mod);
    }
  }
  cout << ans << endl;
  return 0;
}
