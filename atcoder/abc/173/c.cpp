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
    c[i][j] = ((x == '.') ? 0 : 1);
  }

  int ans = 0;

  rep(is, 1 << h) {
    rep(js, 1 << w) {
      int cnt = 0;
      rep(i, h) {
        if (is >> i & 1) continue;
        rep(j, w) {
          if (js >> j & 1) continue;
          cnt += c[i][j];
        }
      }
      if (cnt == k) ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
