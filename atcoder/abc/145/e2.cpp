#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[3005][3005];
int g[3005][3005];

int main() {
  int n, t;
  cin >> n >> t;
  int a[n], b[n];
  rep(i, n) cin >> a[i] >> b[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < t; ++j) {
      int nj = j + a[i];
      if (nj < t) {
        if (dp[i + 1][nj] < dp[i][j] + b[i]) {
          g[i + 1][nj] = 1;
        }
        dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + b[i]);
      }

      if (dp[i + 1][j] < dp[i][j]) g[i + 1][j] = 0;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    }
  }

  set<int> s;
  for (int i = n, j = t - 1; i >= 0; --i) {
    if (g[i][j]) {
      s.insert(i - 1);
      j -= a[i - 1];
    }
  }

  int mx = 0;
  rep(i, n) {
    if (s.find(i) != s.end()) continue;
    mx = max(mx, b[i]);
  }

  int ans = dp[n][t - 1] + mx;

  cout << ans << endl;
  return 0;
}
