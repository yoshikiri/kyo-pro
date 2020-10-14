#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    n /= 2;
    k = k * k % mod;
  }
  return res;
}

ll comb(int n, int k) {
  ll x = 1;
  ll y = 1;
  rep(i, k) {
    x = x * (n - i) % mod;
    y = y * (i + 1) % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    ll ans = comb(k - 1, i - 1);
    ans = ans * comb(n - k + 1, i) % mod;
    cout << ans << endl;
  }
  return 0;
}
