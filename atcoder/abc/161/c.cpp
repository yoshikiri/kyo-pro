#include <iostream>

int main() {
  long long N, K;
  std::cin >> N >> K;

  // N %= K;
  // int a = (N > K ? N - K : K - N);
  // if (N > a) {
  //   std::cout << a << '\n';
  // } else {
  //   std::cout << N << '\n';
  // }

  long long t = N % K;
  if (t < K - t) {
    std::cout << t << '\n';
  } else {
    std::cout << K - t << '\n';
  }

  return 0;
}
