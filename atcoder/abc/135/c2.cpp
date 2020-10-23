#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n];
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 0;
  rep(i, n + 1) ans += a[i];

  rep(i, n) {
    int r = max(0, b[i] - a[i]);
    a[i] = max(0, a[i] - b[i]);
    a[i + 1] = max(0, a[i + 1] - r);
  }
  rep(i, n + 1) ans -= a[i];
  cout << ans << endl;
  return 0;
}
