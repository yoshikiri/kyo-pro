#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Sieve {
  vector<int> p;

  Sieve(int n) : p(n) {
    p[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (p[i] != 0) continue;
      p[i] = i;
      for (ll j = 2 * i; j <= n; j += i) {
        p[j] = i;
      }
    }
  }

  map<int, int> fact(int x) {
    map<int, int> mp;
    while (p[x] != -1) {
      ++mp[p[x]];
      x /= p[x];
    }
    return mp;
  }

  vector<P> factList(int x) {
    auto mp = fact(x);
    vector<P> f;
    for (auto p : mp) {
      f.push_back({p.first, p.second});
    }
    return f;
  }
};

int main() {
  int n;
  cin >> n;

  Sieve s(n);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    // auto fact = s.factList(i);
    auto fact = s.fact(i);
    ll now = 1;
    for (auto p : fact) now *= p.second + 1;
    ans += (ll)i * now;
  }
  cout << ans << endl;
  return 0;
}
