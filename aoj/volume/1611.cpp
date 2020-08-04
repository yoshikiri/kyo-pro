#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<vector<int>> dp;
vector<int> w;

int rec(int l, int r) {
  if (r - l <= 1)
    return 0;
  if (r - l == 2) {
    if (abs(w[l] - w[r - 1]) <= 1)
      return 2;
    else
      return 0;
  }

  if (dp[l][r] != -1)
    return dp[l][r];

  if (abs(w[l] - w[r - 1]) <= 1 && rec(l + 1, r - 1) == r - l - 2)
    dp[l][r] = max(dp[l][r], r - l);

  for (int i = l + 1; i <= r - 1; ++i)
    dp[l][r] = max(dp[l][r], rec(l, i) + rec(i, r));

  return dp[l][r];
}

int main() {
  vector<int> ans;
  while (1) {
    int n;
    cin >> n;
    if (n == 0)
      break;
    w.resize(n);
    rep(i, n) cin >> w[i];

    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    ans.push_back(rec(0, n));

    // for (int W = 2; W <= n; ++W) {
    //   rep(l, n) {
    //     int r = l + W;
    //     if (r > n)
    //       continue;
    //     if (dp[l + 1][r - 1] == W - 2 && abs(w[l] - w[r - 1]) <= 1) {
    //       dp[l][r] = W;
    //     }

    //     for (int m = l; m <= r; ++m) {
    //       dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r]);
    //     }
    //   }
    // }
    // cout << dp[0][n] << endl;
  }

  for (auto x : ans)
    cout << x << endl;
  return 0;
}