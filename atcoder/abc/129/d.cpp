#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w;
  cin >> h >> w;
  int s[h][w];
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    s[i][j] = (c == '#');
  }

  int score[h][w];
  rep(i, h) rep(j, w) score[i][j] = 0;

  // left
  rep(i, h) {
    int l = -1;
    rep(j, w) {
      if (s[i][j])
        l = -1;
      else {
        ++l;
        score[i][j] += l;
      }
    }
  }

  // right
  rep(i, h) {
    int l = -1;
    rep(j, w) {
      if (s[i][w - j - 1])
        l = -1;
      else {
        ++l;
        score[i][w - j - 1] += l;
      }
    }
  }

  // up
  rep(j, w) {
    int l = -1;
    rep(i, h) {
      if (s[i][j])
        l = -1;
      else {
        ++l;
        score[i][j] += l;
      }
    }
  }

  // down
  rep(j, w) {
    int l = -1;
    rep(i, h) {
      if (s[h - i - 1][j])
        l = -1;
      else {
        ++l;
        score[h - i - 1][j] += l;
      }
    }
  }

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j]) continue;
      ans = max(ans, score[i][j] + 1);
    }
  }

  cout << ans << endl;
  return 0;
}
