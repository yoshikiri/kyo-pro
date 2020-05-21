#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1000000007;

ll modpow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll choose(ll n, ll k) {
  ll x = 1, y = 1;
  rep(i, k) {
    x *= (n - i) % mod;
    x %= mod;
    y *= (i + 1) % mod;
    y %= mod;
  }

  ll invy = modpow(y, mod - 2);
  return x * invy % mod;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  ll ans = modpow(2, n) - 1;

  ans -= choose(n, a);
  ans = (ans + mod) % mod;
  ans -= choose(n, b);
  ans = (ans + mod) % mod;
  cout << ans << '\n';

  return 0;
}
