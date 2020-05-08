#include <iostream>

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int K;
  std::cin >> K;

  int sum = 0;

  for (int a = 1; a <= K; a++) {
    for (int b = 1; b <= K; b++) {
      for (int c = 1; c <= K; c++) {
        sum += gcd(gcd(a, b), c);
      }
    }
  }
  std::cout << sum << '\n';
  return 0;
}