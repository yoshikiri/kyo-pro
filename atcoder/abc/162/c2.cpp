#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int k;
  cin >> k;

  int ans = 0;
  for (int a = 1; a <= k; ++a) {
    for (int b = 1; b <= k; ++b) {
      for (int c = 1; c <= k; ++c) { ans += gcd(gcd(a, b), c); }
    }
  }

  cout << ans << '\n';

  return 0;
}
