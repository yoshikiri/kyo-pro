#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  int x[n], y[n];
  rep(i, n) cin >> x[i] >> y[i];

  int ans = 0;
  rep(i, n) {
    ll d2 = (ll)x[i] * x[i] + (ll)y[i] * y[i];
    if (d2 <= (ll)d * d) ++ans;
  }
  cout << ans << endl;
  return 0;
}
