#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Sieve {
  vector<int> p;
  Sieve(int n) : p(n + 1, 1) {
    for (int i = 2; i <= n; ++i) {
      if (p[i] == 1) {
        p[i] = i;
        for (int j = 2 * i; j <= n; j += i) p[j] = i;
      }
    }
  }

  vector<P> fact(int x) {
    map<int, int> mp;
    while (x != 1) {
      ++mp[p[x]];
      x /= p[x];
    }
    vector<P> f;
    for (auto p : mp) f.emplace_back(p.first, p.second);
    return f;
  }
};

int main() {
  int n;
  cin >> n;

  Sieve s(n);
  ll ans = 0;
  for (int c = 1; c <= n; ++c) {
    int ab = n - c;
    if (ab == 0) continue;
    auto f = s.fact(ab);
    ll cnt = 1;
    for (auto p : f) {
      cnt *= (p.second + 1);
    }
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}
