#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int r, c;
  cin >> r >> c;
  int a[r][c];
  rep(i, r) rep(j, c) cin >> a[i][j];

  int ans = 0;
  rep(s, 1 << r) {
    int x[r][c];
    rep(i, r) {
      if (s >> i & 1) {
        rep(j, c) x[i][j] = 1 - a[i][j];
      } else {
        rep(j, c) x[i][j] = a[i][j];
      }
    }

    int now = 0;
    rep(j, c) {
      int sum = 0;
      rep(i, r) sum += x[i][j];
      now += max(sum, r - sum);
    }
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
