#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[105][10005];

int main() {
  int n, W;
  cin >> n >> W;
  int v[n], w[n];
  rep(i, n) cin >> v[i] >> w[i];

  rep(i, n) rep(j, W + 1) {
    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    if (j + w[i] <= W)
      dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
  }

  cout << dp[n][W] << endl;
  return 0;
}
