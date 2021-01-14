#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (s[i] == s[j])
        dp[i][j] = min(dp[i + 1][j + 1] + 1, i - j);
      else
        dp[i][j] = 0;
    }
  }

  int ans = 0;
  rep(i, n) rep(j, n) ans = max(ans, dp[i][j]);
  cout << ans << endl;
  return 0;
}
