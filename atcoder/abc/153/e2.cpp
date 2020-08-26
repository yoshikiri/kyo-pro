#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[1005][10005];
const int INF = 1001001001;

int main() {
  int h, n;
  cin >> h >> n;
  int a[n], b[n];
  rep(i, n) cin >> a[i] >> b[i];

  rep(i, 1005) rep(j, 10005) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i, n) rep(j, h + 1) {
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    int nj = min(j + a[i], h);
    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + b[i]);
    dp[i][nj] = min(dp[i][nj], dp[i][j] + b[i]);
  }

  cout << dp[n][h] << endl;
  return 0;
}
