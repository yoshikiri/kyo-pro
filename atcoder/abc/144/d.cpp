#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  double ans;
  if (a * a * b > 2 * x) {
    ans = atan((double)a * b * b / 2 / x);
  } else {
    ans = atan(2.0 / a * (b - (double)x / (a * a)));
  }
  printf("%.15f\n", ans * 180 / M_PI);
  return 0;
}
