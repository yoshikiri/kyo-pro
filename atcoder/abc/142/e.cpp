#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  int a[m];
  vector<vector<int>> c(m);
  rep(i, m) {
    int x;
    cin >> a[i] >> x;
    rep(j, x) {
      int y;
      cin >> y;
      c[i].push_back(--y);
    }
  }

  ll dp[m + 1][1 << n];
  const int INF = 1001001001;
  rep(i, m + 1) rep(j, 1 << n) dp[i][j] = INF;
  rep(i, m + 1) dp[i][0] = 0;

  rep(i, m) {
    rep(j, 1 << n) {
      int nj = j;
      for (auto v : c[i]) {
        nj |= (1 << v);
      }
      dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + a[i]);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    }
  }

  int ans = dp[m][(1 << n) - 1];
  if (ans >= INF || ans < 0) ans = -1;
  cout << ans << endl;
  return 0;
}
