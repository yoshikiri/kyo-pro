#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) {
    if (i & 1)
      sum -= a[i];
    else
      sum += a[i];
  }
  ll ans[n];
  ans[0] = sum;
  rep(i, n) ans[i + 1] = 2 * a[i] - ans[i];
  rep(i, n) cout << ans[i] << endl;
  return 0;
}
