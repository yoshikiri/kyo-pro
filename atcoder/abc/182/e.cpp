#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vector<int>> s(h, vector<int>(w));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    s[--a][--b] = 1;
  }
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    s[--a][--b] = 2;
  }

  rep(i, h) {
    int now = 0;
    rep(j, w) {
      if (s[i][j] == 1) now = 1;
      if (s[i][j] == 2) now = 0;
      if (ans[i][j] != 1) ans[i][j] = now;
    }
    for (int j = w - 1; j >= 0; --j) {
      if (s[i][j] == 1) now = 1;
      if (s[i][j] == 2) now = 0;
      if (ans[i][j] != 1) ans[i][j] = now;
    }
  }
  rep(j, w) {
    int now = 0;
    rep(i, h) {
      if (s[i][j] == 1) now = 1;
      if (s[i][j] == 2) now = 0;
      if (ans[i][j] != 1) ans[i][j] = now;
    }
    for (int i = h - 1; i >= 0; --i) {
      if (s[i][j] == 1) now = 1;
      if (s[i][j] == 2) now = 0;
      if (ans[i][j] != 1) ans[i][j] = now;
    }
  }

  int cnt = 0;
  rep(i, h) rep(j, w) cnt += ans[i][j];
  cout << cnt << endl;
  return 0;
}
