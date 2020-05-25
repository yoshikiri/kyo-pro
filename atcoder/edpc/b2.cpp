#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  int h[n];
  rep(i, n) cin >> h[i];

  int dp[n];
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int now = 1001001001;
    for (int j = 1; j <= k; ++j) {
      if (i - j < 0) break;
      now = min(now, dp[i - j] + abs(h[i] - h[i - j]));
    }
    dp[i] = now;
  }

  cout << dp[n - 1] << endl;
  return 0;
}
