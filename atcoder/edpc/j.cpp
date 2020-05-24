#include <cstring>
#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

double dp[305][305][305];
int n;
double solve(int i, int j, int k) {
  if (dp[i][j][k] >= 0) return dp[i][j][k];
  // if (i == 0 && j == 0 && k == 0) return 0.0;

  double res = 0;
  if (i > 0) res += solve(i - 1, j, k) * i;
  if (j > 0) res += solve(i + 1, j - 1, k) * j;
  if (k > 0) res += solve(i, j + 1, k - 1) * k;
  res += n;
  res *= 1.0 / (i + j + k);

  return dp[i][j][k] = res;
}

int main() {
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int one = 0, two = 0, thr = 0;
  rep(i, n) {
    if (a[i] == 1) ++one;
    if (a[i] == 2) ++two;
    if (a[i] == 3) ++thr;
  }

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0.0;

  double ans = solve(one, two, thr);
  printf("%.10f\n", ans);
  return 0;
}
