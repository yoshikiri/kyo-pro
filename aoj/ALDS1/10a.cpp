#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int f[45];

int fib(int x) {
  if (f[x]) return f[x];
  if (x == 0 || x == 1) return f[x] = 1;
  return f[x] = fib(x - 1) + fib(x - 2);
}

int main() {
  int n;
  std::cin >> n;

  std::cout << fib(n) << '\n';
  return 0;
}
