#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[20][2][2];

// [0, s]
ll solve(string s) {
  rep(i, 20) rep(j, 2) rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  int n = s.size();
  rep(i, n) {
    int t = s[i] - '0';
    rep(j, 2) rep(k, 2) {
      for (int d = 0; d <= (j ? 9 : t); ++d) {
        dp[i + 1][j || (d < t)][k || d == 4 || d == 9] += dp[i][j][k];
      }
    }
  }

  return dp[n][0][1] + dp[n][1][1];
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = solve(to_string(b)) - solve(to_string(a - 1));
  cout << ans << endl;
  return 0;
}
