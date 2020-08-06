#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  rep(i, n) rep(j, m) cin >> a[i][j];

  ll ans = 0;
  rep(i, m) rep(j, i) {
    ll now = 0;
    rep(k, n) now += max(a[k][i], a[k][j]);
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
