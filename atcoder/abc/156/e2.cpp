#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll modpow(ll k, ll n, int mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = k * ret % mod;
    k = k * k % mod;
    n /= 2;
  }

  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;

  k = min(k, n - 1);

  int mod = 1000000007;

  ll f[n + 1];
  f[0] = f[1] = 1;
  for (int i = 1; i < n; ++i) {
    f[i + 1] = f[i] * (i + 1) % mod;
  }

  ll fi[n + 1];
  rep(i, n + 1) { fi[i] = modpow(f[i], mod - 2, mod); }

  auto ch = [&](int a, int b) {
    return (f[a] * fi[b] % mod) * fi[a - b] % mod;
  };

  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans += ch(n, i) * ch(n - 1, i) % mod;
    ans %= mod;
  }

  cout << ans << '\n';

  return 0;
}
