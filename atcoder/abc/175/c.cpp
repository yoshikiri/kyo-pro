#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  ll p = abs(x) / d;
  if (p >= k) {
    ll ans = min(abs(x - d * k), abs(x + d * k));
    cout << ans << endl;
    return 0;
  }

  if ((k - p) % 2 == 0) {
    ll ans = min(abs(x - d * p), abs(x + d * p));
    cout << ans << endl;
  } else {
    ll ans = min(abs(x - d * p), abs(x + d * p));
    ans = min(abs(ans + d), abs(ans - d));
    cout << ans << endl;
  }
  return 0;
}
