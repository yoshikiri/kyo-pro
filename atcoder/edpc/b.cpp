#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[100005];
const int INF = 1001001001;

int main() {
  int n, k;
  cin >> n >> k;
  int h[n];
  rep(i, n) cin >> h[i];

  rep(i, n) dp[i] = INF;
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i - j < 0) break;
      dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }

  cout << dp[n - 1] << endl;
  return 0;
}
