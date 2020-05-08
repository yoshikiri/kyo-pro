#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  std::cin >> n >> m;

  std::cout << n * (n - 1) / 2 + m * (m - 1) / 2 << '\n';
  return 0;
}
