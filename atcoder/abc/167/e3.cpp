#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 998244353;

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    k = k * k % mod;
    n /= 2;
  }
  return res;
}

// ll choose(ll n, ll k) {
//   if (k == 0) return 1;
//   ll x = 1, y = 1;
//   rep(i, k) {
//     x = x * (n - i) % mod;
//     y = y * (i + 1) % mod;
//   }
//   return x * modpow(y, mod - 2) % mod;
// }

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  ll f[200005], fi[200005];
  f[0] = f[1] = 1;
  rep(i, n + 1) { f[i + 1] = f[i] * (i + 1) % mod; }
  rep(i, n + 1) { fi[i] = modpow(f[i], mod - 2); }

  auto choose = [&](ll x, ll y) {
    return (f[x] * fi[x - y] % mod) * fi[y] % mod;
  };

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += (m * choose(n - 1, i) % mod) * modpow(m - 1, n - 1 - i) % mod;
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}
