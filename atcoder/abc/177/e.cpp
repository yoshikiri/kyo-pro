#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

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
  int a[n];
  rep(i, n) cin >> a[i];
  Sieve sieve(1e6 + 1);

  int g = a[0];
  rep(i, n) g = gcd(g, a[i]);
  if (g != 1) {
    cout << "not coprime" << endl;
    return 0;
  }

  set<int> s;
  rep(i, n) {
    auto f = sieve.fact(a[i]);
    for (auto p : f) {
      if (s.find(p.first) != s.end()) {
        cout << "setwise coprime" << endl;
        return 0;
      }
      s.insert(p.first);
    }
  }
  cout << "pairwise coprime" << endl;
  return 0;
}
