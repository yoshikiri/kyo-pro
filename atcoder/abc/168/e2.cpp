#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MOD = 1000000007;

ll modpow(ll x, ll n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    return modpow((x % MOD) * (x % MOD), n / 2);
  } else {
    return (x % MOD) * (modpow((x % MOD) * (x % MOD), n / 2) % MOD);
  }
}

int main() {
  int n;
  cin >> n;

  ll zero = 0;

  map<pair<ll, ll>, P> mp;

  rep(i, n) {
    ll x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) {
      ++zero;
      continue;
    }

    ll g = gcd(x, y);
    x /= g;
    y /= g;

    if (y < 0) { x = -x, y = -y; }
    if (y == 0 && x < 0) x = -x, y = -y;
    bool rot = x <= 0;
    if (rot) {
      ll temp = x;
      x = y;
      y = -temp;
    }

    if (rot)
      ++mp[{x, y}].first;
    else
      ++mp[{x, y}].second;
  }

  ll ans = 1;
  for (auto p : mp) {
    int s = p.second.first;
    int t = p.second.second;

    ll now = 1;
    now += modpow(2, s) - 1;
    now %= MOD;
    now += modpow(2, t) - 1;
    now %= MOD;
    ans *= now;
    ans %= MOD;
  }

  ans -= 1;
  ans = (ans + MOD) % MOD;
  ans += zero;
  ans %= MOD;

  cout << ans << '\n';

  return 0;
}
