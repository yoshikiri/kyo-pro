#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;

  double ans = sx + (gx - sx) * (double)sy / (sy + gy);
  printf("%.15f\n", ans);
  return 0;
}
