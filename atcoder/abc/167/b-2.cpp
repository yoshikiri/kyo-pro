#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int xa = min(a, k);
  int xb = min(b, k - xa);
  int xc = k - (xa + xb);

  cout << xa - xc << '\n';

  return 0;
}
