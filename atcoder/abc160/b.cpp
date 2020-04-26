#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;

  int sum = 0;
  int a = n / 500;
  int b = (n % 500) / 5;
  sum += 1000 * a + 5 * b;

  std::cout << sum << '\n';
  return 0;
}
