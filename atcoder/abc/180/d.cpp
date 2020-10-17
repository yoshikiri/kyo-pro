#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll x, y;
  ll a, b;
  cin >> x >> y >> a >> b;
  ll ans = 0;
  while (x <= b / (a - 1)) {
    if (x >= y / a) break;
    x *= a;
    ++ans;
  }
  if (x < y) ans += (y - 1 - x) / b;
  cout << ans << endl;
  return 0;
}
