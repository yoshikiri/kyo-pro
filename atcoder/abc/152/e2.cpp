#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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

struct Sieve {
  vector<int> p;
  Sieve(int n) : p(n) {
    for (int i = 2; i <= n; ++i) {
      p[1] = -1;
      if (p[i] == 0) {
        p[i] = i;
        for (int j = 2 * i; j <= n; j += i) {
          if (p[j]) continue;
          p[j] = i;
        }
      }
    }
  }

  map<int, int> factMap(int n) {
    map<int, int> mp;
    while (p[n] != -1) {
      ++mp[p[n]];
      n /= p[n];
    }
    return mp;
  }
};

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  Sieve s(1000005);

  map<int, int> mp;
  rep(i, n) {
    auto m = s.factMap(a[i]);
    for (auto p : m) {
      mp[p.first] = max(mp[p.first], p.second);
    }
  }

  ll lcd = 1;
  for (auto p : mp) {
    rep(i, p.second) { lcd = lcd * p.first % mod; }
  }

  int b[n];
  rep(i, n) { b[i] = lcd * modpow(a[i], mod - 2) % mod; }

  ll ans = 0;
  rep(i, n) { ans = (ans + b[i]) % mod; }

  cout << ans << endl;

  return 0;
}
