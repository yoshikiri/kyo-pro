#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 5 != 0 && i % 3 != 0) ans += i;
  }

  cout << ans << '\n';
  return 0;
}
