#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l, r;
  cin >> l >> r;

  r = min(r, l + 2019);

  int ans = 2019;
  for (int i = l; i < r; ++i)
    for (int j = i + 1; j <= r; ++j) {
      int now = (ll)i * j % 2019;
      ans = min(ans, now);
    }
  cout << ans << endl;
  return 0;
}
