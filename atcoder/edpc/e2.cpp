#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, W;
  cin >> n >> W;
  int w[n + 1], v[n + 1];
  rep(i, n) cin >> w[i + 1] >> v[i + 1];

  const int mv = n * 1000;
  const int INF = 1001001001;
  int dp[n + 1][mv + 1];
  rep(i, mv + 1) dp[0][i] = INF;
  dp[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= mv; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - v[i] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }

  int ans = 0;
  rep(i, mv + 1) {
    if (dp[n][i] <= W) ans = max(ans, i);
  }

  cout << ans << endl;

  return 0;
}
