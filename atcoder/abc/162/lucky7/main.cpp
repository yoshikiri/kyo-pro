#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int a = N % 10;
  if (a == 7) {
    std::cout << "Yes" << '\n';
    return 0;
  }

  int b = (N - a) / 10 % 10;
  if (b == 7) {
    std::cout << "Yes" << '\n';
    return 0;
  }

  int c = (N - N % 100) / 100;
  if (c == 7) {
    std::cout << "Yes" << '\n';
    return 0;
  }

  std::cout << "No" << '\n';
  return 0;
}