#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int x[n];
  rep(i, n) cin >> x[i];

  int ans = 1001001001;
  for (int p = 1; p <= 100; ++p) {
    int now = 0;
    rep(i, n) now += (p - x[i]) * (p - x[i]);
    ans = min(ans, now);
  }

  cout << ans << '\n';
  return 0;
}
