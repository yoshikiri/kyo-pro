#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

double dp[3005][3005];

int main() {
  int n;
  cin >> n;

  double p[n];
  rep(i, n) cin >> p[i];

  dp[0][0] = 1;

  rep(i, n) {
    rep(j, n) {
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
      dp[i + 1][j + 1] += dp[i][j] * p[i];
    }
  }

  double ans = 0;
  for (int i = (n + 1) / 2; i <= n; ++i) { ans += dp[n][i]; }

  printf("%.10f\n", ans);
  return 0;
}
