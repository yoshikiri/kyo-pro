#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l, r;
  cin >> l >> r;
  int ans = 2018;
  rep(i, 2020) {
    for (int j = 1; j < 2020; ++j) {
      if (l + i + j > r) break;
      int m = (ll)(l + i) * (l + i + j) % 2019;
      ans = min(ans, m);
    }
  }
  cout << ans << endl;
  return 0;
}
