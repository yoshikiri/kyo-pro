#include <iostream>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[105][100005];

int main() {
  int n, w;
  cin >> n >> w;
  P a[n];
  rep(i, n) cin >> a[i + 1].first >> a[i + 1].second;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i].first)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
    }
  }

  cout << dp[n][w] << endl;
  return 0;
}
