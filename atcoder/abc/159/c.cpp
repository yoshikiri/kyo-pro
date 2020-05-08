#include <cmath>
#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l;
  std::cin >> l;

  double x, y, z;
  x = y = l / 3.0;
  z = l - (x + y);

  std::cout << std::fixed << std::setprecision(15) << x * y * z << '\n';

  return 0;
}
