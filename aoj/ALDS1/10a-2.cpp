#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int SIZE = 45;
int f[SIZE];

int fib(int n) {
  if (f[n]) return f[n];

  if (n == 0 || n == 1) return f[n] = 1;
  return f[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  std::cin >> n;

  std::cout << fib(n) << '\n';
  return 0;
}
