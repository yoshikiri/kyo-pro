#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int x, int y) {
  if (x % y == 0) {
    return y;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  int x, y;
  std::cin >> x >> y;

  std::cout << gcd(x, y) << '\n';
  return 0;
}