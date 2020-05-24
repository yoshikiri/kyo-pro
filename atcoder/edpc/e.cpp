#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[105][100005];

const int INF = 1001001001;

int main() {
  int n, w;
  cin >> n >> w;
  int a[n][2];
  rep(i, n) rep(j, 2) cin >> a[i + 1][j];

  rep(i, 105) rep(j, 100005) dp[i][j] = INF;
  dp[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 100005; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - a[i][1] >= 0) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i][1]] + a[i][0]);
      }
    }
  }

  ll ans = 0;
  rep(i, 100005) {
    if (dp[n][i] <= w) ans = i;
  }

  cout << ans << endl;
  return 0;
}
