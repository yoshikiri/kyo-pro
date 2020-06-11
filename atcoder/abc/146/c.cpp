#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  ll x;
  cin >> a >> b >> x;

  ll mx = (ll)a * 1e9 + (ll)b * 10;
  if (x >= mx) {
    ll ans = 1e9;
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;
  for (int d = 1; d <= 10; ++d) {
    ll n = (x - (ll)b * d) / a;
    ll y = n;
    int c = 0;
    while (y > 0) {
      y /= 10;
      ++c;
    }

    printf("%d, %d, %lld\n", d, c, n);
    cout << n << endl;

    if (c == d) {
      ans = max(ans, n);
    }
  }

  cout << ans << endl;
  return 0;
}
