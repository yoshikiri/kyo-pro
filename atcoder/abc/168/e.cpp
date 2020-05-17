#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MOD = 1000000007;

ll modpow(ll x, ll n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    return modpow((x % MOD) * (x % MOD), n / 2);
  } else {
    return (x % MOD) * modpow((x % MOD) * (x % MOD), n / 2);
  }
}

int main() {
  int n;
  cin >> n;
  ll a[n], b[n];
  rep(i, n) cin >> a[i] >> b[i];

  map<string, int> d;
  rep(i, n) {
    // cout << to_string((double)a[i] / b[i]) << '\n';
    // cout << to_string(-(double)b[i] / a[i]) << '\n';
    ++d[to_string((double)a[i] / b[i])];
    ++d[to_string(-(double)b[i] / a[i])];
  }

  int ans = modpow(2, n) - 1;

  for (auto p : d) {
    if (p.first < "0") continue;
    cout << p.first << ", " << p.second << '\n';
    if (p.second > 1) {
      ans -= (modpow(2, p.second) - 1 - p.second) * modpow(2, n - p.second);
      ans = (ans + MOD) % MOD;
    }
  }

  cout << ans << '\n';

  return 0;
}
