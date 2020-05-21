#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll modpow(ll k, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = res * k % mod;
    k = k * k % mod;
    n /= 2;
  }

  return res;
}

// nCk
ll choose(ll n, ll k, ll mod) {
  ll x = 1, y = 1;

  rep(i, k) {
    x *= (n - i) % mod;
    x %= mod;
    y *= (i + 1) % mod;
    y %= mod;
  }

  return x * modpow(y, mod - 2, mod) % mod;
}

int main() {
  int n, k;
  cin >> n >> k;

  k = min(k, n - 1);
  const int mod = 1000000007;

  ll f[n + 1];
  f[0] = f[1] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i + 1] = f[i] * (i + 1) % mod;
  }

  ll fi[n + 1];
  rep(i, n + 1) { fi[i] = modpow(f[i], mod - 2, mod); }

  auto ch = [&](int a, int b) {
    return ((f[a] * fi[b] % mod) * fi[a - b]) % mod;
  };

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += ch(n, i) * ch(n - 1, i) % mod;
    ans %= mod;
  }

  // rep(i, k + 1) { ans += choose(n, i, mod) * choose(n - 1, i, mod); }

  cout << ans << '\n';
  return 0;
}
