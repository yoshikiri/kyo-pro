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

ll choose(ll n, ll k, int mod) {
  ll x = 1, y = 1;

  rep(i, k) {
    x *= n - i;
    x %= mod;
    y *= i + 1;
    y %= mod;
  }

  return x * modpow(y, mod - 2, mod) % mod;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  const int mod = 1000000007;

  ll ans = modpow(2, n, mod) - 1;

  ans -= choose(n, a, mod);
  ans = (ans + mod) % mod;
  ans -= choose(n, b, mod);
  ans = (ans + mod) % mod;

  cout << ans << '\n';
  return 0;
}
