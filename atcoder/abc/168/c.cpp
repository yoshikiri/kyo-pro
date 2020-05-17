#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;

  double t = abs(
      ((2 * M_PI * h / 12.0 + M_PI * m / 60.0 / 6.0) - 2 * M_PI * m / 60.0));

  double ans = sqrt((double)a * a + (double)b * b - 2 * a * b * cos(t));

  // ans = sqrt(25.0 - 8 * sqrt(3));

  printf("%.15f\n", ans);
  return 0;
}
