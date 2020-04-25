#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int solve(std::string x, std::string y) {
  int m = x.length();
  int n = y.length();
  int lcs[m + 1][n + 1];
  rep(i, m + 1) lcs[i][0] = 0;
  rep(j, n + 1) lcs[0][j] = 0;

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i - 1] == y[j - 1])
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
    }
  }

  return lcs[m][n];
}

int main() {
  int n;
  std::cin >> n;
  std::string x, y;

  rep(i, n) {
    std::cin >> x >> y;
    std::cout << solve(x, y) << '\n';
  }
  return 0;
}
