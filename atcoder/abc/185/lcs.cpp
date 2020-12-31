#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  rep(i, n + 1) rep(j, m + 1) {
    if (i < n && j < m && s[i] == t[j]) {
      chmax(dp[i + 1][j + 1], dp[i][j] + 1);
    }
    if (i < n) chmax(dp[i + 1][j], dp[i][j]);
    if (j < m) chmax(dp[i][j + 1], dp[i][j]);
  }

  cout << dp[n][m] << endl;
  return 0;
}