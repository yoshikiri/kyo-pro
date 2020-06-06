#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int s[h][w];
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    s[i][j] = c - '0';
  }

  const int INF = 1001001001;
  int ans = INF;
  rep(t, 1 << (h - 1)) {
    int now = __builtin_popcount(t);
    vector<int> block(now + 1, 0);
    rep(c, w) {
      vector<int> temp(block.size(), 0);
      int cur = 0;
      rep(r, h) {
        temp[cur] += s[r][c];
        if (t >> r & 1) ++cur;
      }

      int mx = 0;
      for (auto v : temp) mx = max(mx, v);
      if (mx > k) {
        now = INF;
        break;
      }

      bool ok = true;
      rep(i, block.size()) if (block[i] + temp[i] > k) ok = false;
      if (ok) {
        rep(i, block.size()) block[i] += temp[i];
      } else {
        ++now;
        rep(i, block.size()) block[i] = temp[i];
      }
    }
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}
