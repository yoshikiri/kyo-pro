#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[105][2][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();

  // // 最初は一致している
  // dp[0][1] = 1;
  // rep(i, n) {
  //   dp[i + 1][0] += dp[i][0] * 10;
  //   dp[i + 1][0] += dp[i][1] * (s[i] - '0');
  //   dp[i + 1][1] += dp[i][1];
  // }

  // cout << dp[n][0] << ", " << dp[n][1] << endl;

  // [0, s]で3を含むもの
  dp[0][0][0] = 1;
  rep(i, n) {
    int t = s[i] - '0';
    rep(j, 2) rep(k, 2) for (int d = 0; d <= (j ? 9 : t); ++d)
        dp[i + 1][j || (d < t)][k || (d == 3)] += dp[i][j][k];
  }
  cout << dp[n][1][1] + dp[n][0][1] << endl;
  return 0;
}
