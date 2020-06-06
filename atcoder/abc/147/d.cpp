#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];

  ll mx = 0;
  rep(i, n) mx = max(mx, a[i]);
  int l = 0;
  while (mx > 0) {
    mx /= 2;
    ++l;
  }

  ll ans = 0;
  rep(i, l) {
    ll x = 1;
    rep(j, i) {
      x *= 2;
      x %= mod;
    }
    ll y = 0;
    rep(j, n) if (a[j] >> i & 1) { ++y; }
    ans += (y * (n - y) % mod) * x % mod;
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}
