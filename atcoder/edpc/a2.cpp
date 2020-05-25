#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  int dp[n];
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
    if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;
  return 0;
}
