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

int main() {
  int s;
  cin >> s;
  int n = s / 3;

  vector<ll> f(s + 1, 1), fi(s + 1);
  rep(i, s) f[i + 1] = f[i] * (i + 1) % mod;
  rep(i, s + 1) fi[i] = modpow(f[i], mod - 2);
  auto comb = [&](int a, int b) {
    if (a == 0 && b == 0) return 1LL;
    if (a <= 0 || a < b) return 0LL;
    return (f[a] * (fi[b] * fi[a - b] % mod)) % mod;
  };
  ll ans = 0;
  rep(i, n) { ans = (ans + comb(s - 2 * i - 3, i)) % mod; }
  cout << ans << endl;
  return 0;
}
