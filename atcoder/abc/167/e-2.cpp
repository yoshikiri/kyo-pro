#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll modpow(ll k, ll n, int mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = ret * k % mod;
    k = k * k % mod;
    n /= 2;
  }

  return ret;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  const int mod = 998244353;

  ll f[n + 1];
  f[0] = f[1] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i + 1] = f[i] * (i + 1) % mod;
  }

  ll fi[n + 1];
  for (int i = 0; i <= n; ++i) {
    fi[i] = modpow(f[i], mod - 2, mod);
  }

  auto choose = [&](int a, int b) {
    return (f[a] * fi[b] % mod) * fi[a - b] % mod;
  };

  ll ans = 0;
  for (int x = 0; x <= k; ++x) {
    ans += (choose(n - 1, x) * m % mod) * modpow(m - 1, n - x - 1, mod) % mod;
    ans %= mod;
  }

  cout << ans << '\n';

  return 0;
}
