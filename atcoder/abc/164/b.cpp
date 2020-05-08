#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  while (1) {
    c -= b;
    if (c <= 0) {
      std::cout << "Yes" << '\n';
      break;
    }

    a -= d;
    if (a <= 0) {
      std::cout << "No" << '\n';
      break;
    }
  }
  return 0;
}
