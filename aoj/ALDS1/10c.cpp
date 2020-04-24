#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int lcs(std::string x, std::string y) {
  int lx = x.length();
  int ly = y.length();

  int c[lx + 1][ly + 1];
  rep(i, lx + 1) c[i][0] = 0;
  rep(j, ly + 1) c[0][j] = 0;

  for (int i = 1; i < lx + 1; ++i) {
    for (int j = 1; j < ly + 1; ++j) {
      if (x[i - 1] == y[j - 1])
        c[i][j] = c[i - 1][j - 1] + 1;
      else
        c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
    }
  }

  return c[lx][ly];
}

int main() {
  int n;
  std::cin >> n;
  std::string x, y;
  rep(i, n) {
    std::cin >> x >> y;
    std::cout << lcs(x, y) << '\n';
  }

  return 0;
}
