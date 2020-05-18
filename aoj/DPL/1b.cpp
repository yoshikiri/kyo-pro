#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int dp[101][10001];

int main() {
  int N, W;
  cin >> N >> W;

  int v[N + 1], w[N + 1];
  for (int i = 1; i <= N; ++i) cin >> v[i] >> w[i];

  for (int i = 0; i <= N; ++i) dp[i][0] = 0;
  for (int j = 0; j <= W; ++j) dp[0][j] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= W; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - w[i] < 0) continue;
      dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }

  // rep(i, N + 1) {
  //   rep(j, W + 1) cout << dp[i][j] << " ";
  //   cout << '\n';
  // }

  cout << dp[N][W] << '\n';

  return 0;
}
