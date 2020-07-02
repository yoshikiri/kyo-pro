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

  vector<ll> f(2005), fi(2005);
  f[0] = 1;
  rep(i, 2004) f[i + 1] = (i + 1) * f[i] % mod;
  rep(i, 2005) fi[i] = modpow(f[i], mod - 2);

  auto choose = [&](int a, int b) {
    if (a < b) return 0LL;
    return (f[a] * fi[b] % mod) * fi[a - b] % mod;
  };

  for (int i = 1; i <= k; ++i) {
    ll now = choose(n - k + 1, i);
    now = now * choose(k - 1, i - 1) % mod;
    cout << now << endl;
  }
  return 0;
}
