#include <iostream>

int main() {
  int N;
  std::cin >> N;

  long long sum = 0;
  for (int i = 0; i <= N; i++) {
    if (i % 3 != 0 && i % 5 != 0) {
      sum += i;
    }
  }

  std::cout << sum << '\n';
  return 0;
}