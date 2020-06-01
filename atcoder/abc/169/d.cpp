#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Sieve {
  vector<ll> p;

  Sieve(ll n) : p(n + 1, 1) {
    p[1] = 0;
    for (ll i = 2; i <= n; ++i) {
      if (p[i] != 1) continue;
      p[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        if (p[j] == 1) p[j] = i;
      }
    }
  }

  vector<ll> factorList(ll x) {
    vector<ll> f;
    while (p[x] != 0) {
      f.push_back(p[x]);
      x /= p[x];
    }
    return f;
  }

  // map<ll, ll> factor(ll x) {
  //   auto l = factorList(x);
  //   map<ll, ll> mp;
  //   for (auto v : l) {
  //     ++mp[v];
  //   }
  //   return mp;
  // }

  vector<pair<ll, int>> factor(ll x) {
    vector<pair<ll, int>> fs;
    for (ll i = 2; i * i <= x; ++i) {
      int cnt = 0;
      while (x % i == 0) x /= i, ++cnt;
      if (cnt != 0) fs.push_back({i, cnt});
    }

    if (x != 1) fs.push_back({x, 1});
    return fs;
  }

  bool isPrime(ll x) { return p[x] == x; }
};

int main() {
  ll n;
  cin >> n;

  // int ans = 0;
  // for (int i = 2; (ll)i * i <= n; ++i) {
  //   if (n % i != 0) continue;
  //
  //   int p = i;
  //   while (n % p == 0) {
  //     n /= p;
  //     p *= i;
  //     ++ans;
  //   }
  //
  //   while (n % i == 0) n /= i;
  // }
  //
  // if (n != 1) ++ans;
  // cout << ans << endl;

  // auto s = Sieve(sqrt(n) + 1);
  //
  // ll ans = 0;
  // for (int i = 2; (ll)i * i <= n; ++i) {
  //   if (!s.isPrime(i)) continue;
  //   int d = i;
  //   while (n % d == 0) {
  //     n /= d;
  //     d *= i;
  //     ++ans;
  //   }
  //
  //   while (n % i == 0) n /= i;
  // }
  //
  // if (n != 1) ++ans;
  // cout << ans << endl;

  vector<pair<ll, int>> fs;
  for (ll i = 2; i * i <= n; ++i) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    if (cnt != 0) fs.push_back({i, cnt});
  }
  if (n != 1) fs.push_back({n, 1});

  int ans = 0;
  for (auto p : fs) {
    int e = p.second;
    int a = 1;
    while (e - a >= 0) {
      e -= a;
      ++a;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
