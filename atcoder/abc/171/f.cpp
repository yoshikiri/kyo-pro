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
  int k;
  string s;
  cin >> k >> s;

  int n = s.size();

  ll f[n + k + 1];
  f[0] = 1;
  rep(i, n + k) { f[i + 1] = (i + 1) * f[i] % mod; }

  ll fi[n + k + 1];
  rep(i, n + k + 1) fi[i] = modpow(f[i], mod - 2);

  auto choose = [&](ll x, ll y) {
    return (f[x] * fi[y] % mod) * fi[x - y] % mod;
  };

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ll now = modpow(26, k - i);
    now = now * modpow(25, i) % mod;
    now = now * choose(n - 1 + i, n - 1) % mod;
    ans = (ans + now) % mod;
  }
  cout << ans << endl;
  return 0;
}
