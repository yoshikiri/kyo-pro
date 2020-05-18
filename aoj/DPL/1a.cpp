#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int dp[25][50005];

const int INF = 1 << 21;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> c(m + 1);
  for (int i = 1; i <= m; ++i) { cin >> c[i]; }

  rep(i, n + 1) dp[0][i] = INF;
  rep(i, m + 1) dp[i][0] = 0;

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - c[i] < 0) continue;
      dp[i][j] = min(dp[i][j], dp[i][j - c[i]] + 1);
    }
  }

  cout << dp[m][n] << '\n';

  return 0;
}
