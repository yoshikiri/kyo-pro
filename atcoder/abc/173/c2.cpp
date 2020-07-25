#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int c[h][w];
  rep(i, h) rep(j, w) {
    char x;
    cin >> x;
    c[i][j] = (x == '#');
  }

  int ans = 0;
  rep(sh, 1 << h) {
    rep(sw, 1 << w) {
      int b = 0;
      rep(i, h) rep(j, w) {
        if (sh >> i & 1 || sw >> j & 1) continue;
        if (c[i][j]) ++b;
      }
      if (b == k) ++ans;
    }
  }
  cout << ans << endl;

  return 0;
}
