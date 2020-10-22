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
  int n;
  cin >> n;
  ll ans = modpow(10, n) - modpow(9, n) - modpow(9, n) + modpow(8, n);
  ans = (ans % mod + mod) % mod;
  cout << ans << endl;
  return 0;
}
