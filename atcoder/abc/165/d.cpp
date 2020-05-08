#include <iostream>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a;
  ll b, n;
  std::cin >> a >> b >> n;

  ll x;
  if (n < b - 1)
    x = n;
  else
    x = b - 1;

  std::cout << (a * x) / b + a * (x / b) << '\n';

  return 0;
}
