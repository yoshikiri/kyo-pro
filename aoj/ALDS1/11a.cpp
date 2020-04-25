#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  int a[n][n];
  rep(i, n) rep(j, n) a[i][j] = 0;

  rep(i, n) {
    int u, k, v;
    std::cin >> u >> k;
    rep(j, k) {
      std::cin >> v;
      a[u - 1][v - 1] = 1;
    }
  }

  rep(i, n) {
    rep(j, n) {
      if (j) std::cout << ' ';
      std::cout << a[i][j];
    }
    std::cout << '\n';
  }
  return 0;
}
