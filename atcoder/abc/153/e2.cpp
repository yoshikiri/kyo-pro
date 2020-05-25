#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[1005][20005];

int main() {
  int h, n;
  cin >> h >> n;
  int a[n], b[n];
  rep(i, n) cin >> a[i] >> b[i];

  const int INF = 1001001001;
  rep(i, n) rep(j, h + 1) dp[i][j] = INF;
  dp[0][0] = 0;

  rep(i, n) {
    rep(j, h) {
      dp[i + 1][j] = dp[i][j];
      int nj = min(j + a[i], h);
      dp[i][nj] = min(dp[i][nj], dp[i][j] + b[i]);
    }
  }

  rep(i, n) {
    rep(j, h + 1) { cout << dp[i][j] << " "; }
    cout << endl;
  }

  cout << dp[n - 1][h] << endl;

  return 0;
}
