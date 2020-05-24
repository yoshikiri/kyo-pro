#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[3005][3005];

int main() {
  string s, t;
  cin >> s >> t;

  int S = s.length(), T = t.length();

  rep(i, S) dp[i][0] = 0;
  rep(i, T) dp[0][i] = 0;

  rep(i, S) {
    rep(j, T) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  string ans = "";
  int i = S, j = T;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j])
      --i;
    else if (dp[i][j] == dp[i][j - 1])
      --j;
    else {
      ans = s[i - 1] + ans;
      --i, --j;
    }
  }

  cout << ans << endl;
  return 0;
}
