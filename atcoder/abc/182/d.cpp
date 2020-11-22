#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll x = 0, s = 0, mxs = 0;
  rep(i, n) {
    s += a[i];
    mxs = max(mxs, s);
    ans = max(ans, x + mxs);
    x += s;
  }

  cout << ans << endl;
  return 0;
}
