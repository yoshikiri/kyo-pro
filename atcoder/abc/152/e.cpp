#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// const int mod = 1000000007;
const int mod = 1e9 + 7;

const int MAX = 1000005;

struct Sieve {
  int n;
  vector<int> f, primes;

  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }

  bool isPrime(int x) { return f[x] == x; }

  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }

  vector<P> factor(int x) {
    auto fl = factorList(x);

    map<int, int> mp;
    for (auto p : fl) ++mp[p];

    vector<P> res;
    for (auto p : mp) res.push_back(p);

    return res;
  }
};

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
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  Sieve s(MAX);

  map<int, int> mp;
  rep(i, n) {
    auto v = s.factor(a[i]);
    for (auto p : v) {
      mp[p.first] = max(mp[p.first], p.second);
    }
  }

  ll lcm = 1;
  for (auto p : mp) {
    rep(i, p.second) { lcm = lcm * p.first % mod; }
  }

  ll ans = 0;
  rep(i, n) {
    ans += lcm * modpow(a[i], mod - 2);
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}
