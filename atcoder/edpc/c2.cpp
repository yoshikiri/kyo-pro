#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int d[n][3];
  rep(i, n) rep(j, 3) cin >> d[i][j];

  int dp[n + 1][3];
  rep(i, 3) dp[0][i] = 0;

  rep(i, n) {
    rep(j, 3) {
      int j1 = (j + 1) % 3, j2 = (j + 2) % 3;
      dp[i + 1][j] = max(dp[i][j1] + d[i][j1], dp[i][j2] + d[i][j2]);
    }
  }

  int ans = 0;
  rep(i, 3) ans = max(ans, dp[n][i]);
  cout << ans << endl;

  return 0;
}
