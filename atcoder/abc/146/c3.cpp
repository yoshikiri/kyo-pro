#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  ll x;
  cin >> a >> b >> x;

  auto d = [](int n) {
    int cnt = 0;
    while (n > 0) {
      n /= 10;
      ++cnt;
    }
    return cnt;
  };

  auto f = [&](int n) { return (ll)a * n + (ll)b * d(n); };

  if (f(1e9) <= x) {
    cout << 1000000000 << endl;
    return 0;
  }

  ll l = 0, r = 1e9 + 1;
  while (l + 1 < r) {
    ll c = (l + r) / 2;
    if (f(c) <= x)
      l = c;
    else
      r = c;
  }

  cout << l << endl;
  return 0;
}
