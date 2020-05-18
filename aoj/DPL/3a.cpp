#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  int c[h][w];
  rep(i, h) rep(j, w) cin >> c[i][j];

  int dp[h + 1][w + 1];

  int ans = 0;

  rep(i, h) rep(j, w) {
    dp[i][j] = (c[i][j] + 1) % 2;
    if (dp[i][j]) ans = 1;
  }

  for (int i = 1; i < h; ++i) {
    for (int j = 1; j < w; ++j) {
      if (c[i][j])
        dp[i][j] = 0;
      else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }

  cout << ans * ans << '\n';

  return 0;
}
