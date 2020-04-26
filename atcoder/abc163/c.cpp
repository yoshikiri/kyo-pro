#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  std::cin >> n;
  int a[n - 1];
  rep(i, n - 1) std::cin >> a[i];

  int b[n];
  rep(i, n) b[i] = 0;

  rep(i, n - 1) { b[a[i] - 1]++; }

  rep(i, n) { std::cout << b[i] << '\n'; }
  return 0;
}
