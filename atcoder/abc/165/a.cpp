// 18:05 -
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k, a, b;
  std::cin >> k >> a >> b;

  for (int i = a; i <= b; ++i) {
    if (i % k == 0) {
      std::cout << "OK" << '\n';
      return 0;
    }
  }

  std::cout << "NG" << '\n';
  return 0;
}
