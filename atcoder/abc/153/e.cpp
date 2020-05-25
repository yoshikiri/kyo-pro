#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[1005][20005];

int main() {
  int h, n;
  cin >> h >> n;
  int a[n + 1], b[n + 1];
  rep(i, n) cin >> a[i + 1] >> b[i + 1];

  int mx = 0;
  rep(i, n) mx = max(mx, a[i + 1]);

  const int INF = 1001001001;
  rep(i, 20005) dp[0][i] = INF;
  dp[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= h + mx; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - a[i] >= 0) {
        dp[i][j] = min(dp[i][j],
                       min(dp[i][j - a[i]] + b[i], dp[i - 1][j - a[i]] + b[i]));
      }
    }
  }

  int ans = INF;
  rep(i, mx) {
    if (dp[n][h + i]) ans = min(ans, dp[n][h + i]);
  }
  cout << ans << endl;
  return 0;
}
