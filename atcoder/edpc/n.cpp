#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll dp[410][410];
ll a[410], b[410];

const ll INF = 1e18;

ll rec(int l, int r) {
  if (r - l <= 1)
    return 0;
  if (r - l == 2)
    return a[l] + a[r - 1];

  if (dp[l][r] != INF)
    return dp[l][r];

  for (int i = l + 1; i <= r - 1; ++i) {
    dp[l][r] = min(dp[l][r], rec(l, i) + rec(i, r) + b[r] - b[l]);
  }
  return dp[l][r];
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) b[i + 1] = b[i] + a[i];

  rep(i, n + 1) rep(j, n + 1) dp[i][j] = INF;
  cout << rec(0, n) << endl;
  return 0;
}
