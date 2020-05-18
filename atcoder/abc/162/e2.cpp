#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1000000007;

ll modpow(ll x, ll n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    return modpow((x % mod) * (x % mod), n / 2);
  } else {
    return (x % mod) * (modpow((x % mod) * (x % mod), n / 2) % mod);
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> d(k + 1);

  for (int i = 1; i <= k; ++i) d[i] = modpow(k / i, n);

  for (int i = k; i >= 1; --i) {
    for (int j = 2 * i; j <= k; j += i) {
      d[i] -= d[j];
      d[i] = (d[i] + mod) % mod;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += i * d[i];
    ans %= mod;
  }

  cout << ans << '\n';

  return 0;
}
