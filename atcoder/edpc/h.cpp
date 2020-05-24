#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[1005][1005];

const int mod = 1000000007;

int main() {
  int h, w;
  cin >> h >> w;

  bool a[h][w];
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    a[i][j] = (c == '.');
  }

  dp[0][0] = 1;

  rep(i, h) rep(j, w) {
    if (a[i + 1][j]) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= mod;
    }
    if (a[i][j + 1]) {
      dp[i][j + 1] += dp[i][j];
      dp[i][j + 1] %= mod;
    }
  }

  cout << dp[h - 1][w - 1] << endl;

  return 0;
}
