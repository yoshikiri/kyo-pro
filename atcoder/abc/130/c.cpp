#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll w, h;
  int x, y;
  cin >> w >> h >> x >> y;

  printf("%.10f ", w * h / 2.0);
  cout << ((ll)(2 * x) == w && (ll)(2 * y) == h ? 1 : 0) << endl;

  return 0;
}
