#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, W;
  cin >> n >> W;
  int w[n], v[n];
  rep(i, n) cin >> w[i] >> v[i];

  int dp[n + 1][W + 1];
  rep(i, n + 1) rep(j, W + 1) dp[i][j] = 0;

  rep(i, n) {
    rep(j, W) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      int nj = j + w[i];
      if (nj <= W) dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + v[i]);
    }
  }

  cout << dp[n][W] << endl;
  return 0;
}
