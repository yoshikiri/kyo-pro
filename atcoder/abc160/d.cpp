#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAX = 2000;
int a[MAX][MAX];

int main() {
  int n, x, y;
  std::cin >> n >> x >> y;

  int d[MAX] = {0};

  rep(i, n) for (int j = i + 1; j < n; ++j) {
    a[i][j] = std::min(std::abs(j - i),
                       std::abs(x - 1 - i) + 1 + std::abs(y - 1 - j));
    d[a[i][j]]++;
  }

  for (int k = 1; k < n; ++k) {
    std::cout << d[k] << '\n';
  }
  return 0;
}
