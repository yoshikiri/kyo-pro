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

ll choose(ll n, ll k) {
  ll x = 1, y = 1;
  rep(i, k) {
    x = x * (n - i) % mod;
    y = y * (i + 1) % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main() {
  int x, y;
  cin >> x >> y;

  if ((x + y) % 3 != 0) {
    puts("0");
    return 0;
  }

  int z = (x + y) / 3;
  int r = x - z;
  int u = y - z;

  if (r < 0 || u < 0) {
    puts("0");
    return 0;
  }

  ll ans = choose(r + u, r);
  cout << ans << endl;
  return 0;
}
