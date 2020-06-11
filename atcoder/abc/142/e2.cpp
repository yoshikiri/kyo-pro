#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> k(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    int t = 0;
    rep(j, b) {
      int c;
      cin >> c;
      --c;
      t |= 1 << c;
    }
    k[i] = P(a, t);
  }

  const int INF = 1001001001;
  // int dp[m + 1][1 << n];
  // rep(i, m + 1) rep(j, 1 << n) dp[i][j] = INF;
  // dp[0][0] = 0;
  // rep(i, m) rep(j, 1 << n) {
  //   int nj = j;
  //   nj |= k[i].second;
  //   dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + k[i].first);
  //   dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
  // }

  // int ans = dp[m][(1 << n) - 1];
  // if (ans == INF) ans = -1;

  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  rep(s, 1 << n) {
    rep(i, m) {
      int t = s | k[i].second;
      int cost = dp[s] + k[i].first;
      dp[t] = min(dp[t], cost);
    }
  }
  int ans = dp.back();
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
