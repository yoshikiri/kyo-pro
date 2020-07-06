#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int dp[100005][2];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  dp[0][0] = 1;

  rep(i, n) {
    { // a + b = 0
      if (s[i] == '0') {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
      } else {
        dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
      }
    }

    { // a + b = 1
      if (s[i] == '0') {
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      } else {
        (dp[i + 1][0] += dp[i][0] * 2 % mod) %= mod;
        (dp[i + 1][1] += dp[i][1] * 2 % mod) %= mod;
      }
    }
  }

  int ans = (dp[n][0] + dp[n][1]) % mod;
  cout << ans << endl;
  return 0;
}
