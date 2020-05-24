#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[100005][3];

int main() {
  int n;
  cin >> n;
  int d[n][3];
  rep(i, n) rep(j, 3) cin >> d[i][j];

  for (int i = 0; i < n; ++i) {
    dp[i + 1][0] = max(dp[i][1], dp[i][2]) + d[i][0];
    dp[i + 1][1] = max(dp[i][2], dp[i][0]) + d[i][1];
    dp[i + 1][2] = max(dp[i][0], dp[i][1]) + d[i][2];
  }

  int ans = 0;
  rep(i, 3) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
