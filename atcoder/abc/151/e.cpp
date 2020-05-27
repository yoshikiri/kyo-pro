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
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];

  ll c[n];
  c[0] = 0;
  rep(i, n - 1) {
    if (i + 1 < k - 1)
      c[i + 1] = 0;
    else if (i + 1 == k - 1)
      c[i + 1] = 1;
    else
      c[i + 1] = (c[i] * (i + 1) % mod) * modpow(i - k + 2, mod - 2) % mod;
  }

  // rep(i, n) { cout << c[i] << endl; }

  sort(a, a + n);
  ll ans = 0;
  rep(i, n) {
    ans -= a[i] * c[n - i - 1] % mod;
    ans = (ans + mod) % mod;
    ans += a[i] * c[i] % mod;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}
