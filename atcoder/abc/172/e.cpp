#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    k = k * k % mod;
    n /= 2;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;

  ll f[m + 1];
  f[0] = 1;
  rep(i, m) f[i + 1] = (i + 1) * f[i] % mod;
  ll fi[m + 1];
  rep(i, m + 1) fi[i] = modpow(f[i], mod - 2);

  auto p = [&](ll a, ll b) { return f[a] * fi[a - b] % mod; };

  auto choose = [&](ll a, ll b) {
    return (f[a] * fi[b] % mod) * fi[a - b] % mod;
  };

  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ll now = choose(n, i);
    now = now * p(m - i, n - i) % mod;
    if (i & 1) now = mod - now;
    ans = (ans + now) % mod;
  }
  ans = ans * p(m, n) % mod;
  cout << ans << endl;
  return 0;
}
