#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  std::cin >> a >> b;

  double minv = (12.5 * a > 10 * b) ? 12.5 * a : 10 * b;
  double maxv = (12.5 * (a + 1) > 10 * (b + 1)) ? 12.5 * (a + 1) : 10 * (b + 1);

  for (int k = minv - 1; k <= maxv + 1; ++k) {
    if ((int)(k * 0.08) == a && (int)(k * 0.1) == b) {
      std::cout << k << '\n';
      return 0;
    }
  }

  std::cout << -1 << '\n';
  return 0;
}
