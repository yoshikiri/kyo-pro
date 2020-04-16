#include <algorithm>
#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int a[N];
  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
  }

  std::sort(a, a + N);
  // for (int i = 0; i < N; i++) {
  //   std::cout << a[i] << '\n';
  // }

  int alice = 0, bob = 0;
  for (int i = N - 1; i >= 0; i -= 2) {
    alice += a[i];
    if (i - 1 < 0)
      break;
    bob += a[i - 1];
  }

  std::cout << alice - bob << '\n';
}