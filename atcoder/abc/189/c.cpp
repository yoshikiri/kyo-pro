#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int ans = 0;
  rep(l, n) {
    int mn = 1001001001;
    int t = 0;
    for (int r = l; r < n; ++r) {
      mn = min(mn, a[r]);
      t = max(t, mn * (r - l + 1));
    }
    ans = max(ans, t);
  }

  cout << ans << endl;
  return 0;
}
