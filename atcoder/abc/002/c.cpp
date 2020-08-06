#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x[3], y[3];
  rep(i, 3) cin >> x[i] >> y[i];
  int x1 = x[1] - x[0];
  int x2 = x[2] - x[0];
  int y1 = y[1] - y[0];
  int y2 = y[2] - y[0];
  printf("%.5f\n", abs(x1 * y2 - x2 * y1) / 2.0);
  return 0;
}
