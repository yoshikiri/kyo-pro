#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[101][4][4][4];
const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  dp[0][3][3][3] = 1;

  // ACGT 0123
  for (int len = 0; len < n; ++len) {
    for (int c1 = 0; c1 < 4; ++c1) {
      for (int c2 = 0; c2 < 4; ++c2) {
        for (int c3 = 0; c3 < 4; ++c3) {
          for (int c = 0; c < 4; ++c) {
            if (c == 2 && c1 == 1 && c2 == 0) continue;
            if (c == 2 && c1 == 0 && c2 == 1) continue;
            if (c == 1 && c1 == 2 && c2 == 0) continue;
            if (c == 2 && c1 == 1 && c3 == 0) continue;
            if (c == 2 && c2 == 1 && c3 == 0) continue;

            dp[len + 1][c][c1][c2] += dp[len][c1][c2][c3];
            dp[len + 1][c][c1][c2] %= MOD;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int c1 = 0; c1 < 4; ++c1) {
    for (int c2 = 0; c2 < 4; ++c2) {
      for (int c3 = 0; c3 < 4; ++c3) {
        ans += dp[n][c1][c2][c3];
        ans %= MOD;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
