#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[100005][3];

int convert(char c) {
  int x;
  if (c == 'r') x = 0;
  if (c == 's') x = 1;
  if (c == 'p') x = 2;
  return x;
}

int main() {
  int n, k, a[3];
  cin >> n >> k;
  rep(i, 3) cin >> a[i];
  string t;
  cin >> t;

  auto b = vector<vector<int>>(k);

  for (int i = 0; i < n; ++i) {
    int x = convert(t[i]);
    b[i % k].push_back(x);
  }

  int ans = 0;
  rep(order, k) {
    int m = b[order].size();
    int dp[m + 1][3];
    rep(i, m + 1) rep(j, 3) dp[i][j] = 0;

    for (int i = 0; i < m; ++i) {
      int score[3];
      rep(j, 3) score[j] = 0;
      if (b[order][i] == 0) score[2] = a[2];
      if (b[order][i] == 1) score[0] = a[0];
      if (b[order][i] == 2) score[1] = a[1];

      rep(j, 3) rep(k, 3) {
        if (j == k) continue;
        dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + score[k]);
      }
    }

    int now = 0;
    rep(i, 3) now = max(now, dp[m][i]);
    ans += now;
  }

  cout << ans << endl;
  return 0;
}
