#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w;
  cin >> h >> w;
  string s[h];
  rep(i, h) cin >> s[i];
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) {
    int l = 0, r = 0;
    rep(j, w) {
      if (s[i][j] == '.')
        ++l;
      else
        l = 0;
      if (s[i][w - 1 - j] == '.')
        ++r;
      else
        r = 0;
      a[i][j] += l;
      a[i][w - j - 1] += r;
    }
  }

  rep(j, w) {
    int l = 0, r = 0;
    rep(i, h) {
      if (s[i][j] == '.')
        ++l;
      else
        l = 0;
      if (s[h - i - 1][j] == '.')
        ++r;
      else
        r = 0;
      a[i][j] += l;
      a[h - i - 1][j] += r;
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, a[i][j]);
  cout << ans - 3 << endl;
  return 0;
}
