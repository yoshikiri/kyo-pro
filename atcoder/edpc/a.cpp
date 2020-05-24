#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[100005];

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  dp[0] = 0, dp[1] = abs(h[0] - h[1]);
  for (int i = 2; i < n; ++i) {
    dp[i] =
        min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[n - 1] << endl;
  return 0;
}
