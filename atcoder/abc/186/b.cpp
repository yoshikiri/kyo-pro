#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w;
  cin >> h >> w;
  int a[h][w];
  rep(i, h) rep(j, w) cin >> a[i][j];
  int mn = 10000;
  rep(i, h) rep(j, w) mn = min(mn, a[i][j]);

  int ans = 0;
  rep(i, h) rep(j, w) ans += a[i][j] - mn;
  cout << ans << endl;
  return 0;
}
