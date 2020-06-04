#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;

  ll a[n + 2];
  a[0] = 0;
  rep(i, n + 1) a[i + 1] = a[i] + i;

  ll ans = 0;
  for (int i = k; i <= n + 1; ++i) {
    ll mn = a[i], mx = a[n + 1] - a[n + 1 - i];
    ans += (mx - mn + 1) % mod;
  }
  ans %= mod;
  cout << ans << endl;

  return 0;
}
