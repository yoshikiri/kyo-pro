#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];

  rep(i, n) if (a[i] == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  rep(i, n) {
    ll lim = (ll)(1e18) / ans;
    if (a[i] > lim) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }

  cout << ans << endl;
  return 0;
}
