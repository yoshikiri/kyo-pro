#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  printf("%.15f ", (ll)w * h / 2.0);
  if ((ll)2 * x == w && (ll)2 * y == h)
    cout << "1" << endl;
  else
    cout << "0" << endl;
  return 0;
}
