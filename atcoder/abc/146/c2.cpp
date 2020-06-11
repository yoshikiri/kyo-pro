#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  ll x;
  cin >> a >> b >> x;

  auto k = [](ll c) {
    int res = 0;
    while (c > 0) {
      c /= 10;
      ++res;
    }
    return res;
  };

  auto f = [&](ll c) { return (ll)a * c + (ll)b * k(c); };

  ll ok = 0, ng = 1e9 + 1;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (f(mid) <= x)
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;
  return 0;
}
