#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  std::cin >> x;

  for (int i = -119; i <= 118; ++i) {
    for (int j = -119; j <= 118; ++j) {
      if (std::pow(i, 5) - std::pow(j, 5) == x) {
        std::cout << i << ' ' << j << '\n';
        return 0;
      }
    }
  }
  return 0;
}
