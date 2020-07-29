#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[105][4][4][4];
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  dp[0][3][3][3] = 1;
  rep(i, n) rep(j, 4) rep(k, 4) rep(l, 4) {
    rep(m, 4) {
      if (j == 0 && l == 2 && m == 1) continue; // A?GC
      if (j == 0 && k == 2 && m == 1) continue; // AG?C
      if (k == 0 && l == 2 && m == 1) continue; // AGC
      if (k == 2 && l == 0 && m == 1) continue; // GAC
      if (k == 0 && l == 1 && m == 2) continue; // ACG

      dp[i + 1][k][l][m] += dp[i][j][k][l];
      dp[i + 1][k][l][m] %= mod;
    }
  }

  ll ans = 0;
  rep(j, 4) rep(k, 4) rep(l, 4) {
    ans += dp[n][j][k][l];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
