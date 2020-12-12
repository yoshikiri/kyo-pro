#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int X = 100;
double dp[X + 1][X + 1][X + 1];

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = X - 1; i >= 0; --i) {
    for (int j = X - 1; j >= 0; --j) {
      for (int k = X - 1; k >= 0; --k) {
        if (i + j + k == 0) continue;
        double now = 0;
        now += dp[i + 1][j][k] * i;
        now += dp[i][j + 1][k] * j;
        now += dp[i][j][k + 1] * k;
        dp[i][j][k] = now / (i + j + k) + 1;
      }
    }
  }
  double ans = dp[a][b][c];
  printf("%.10f\n", ans);
  return 0;
}
