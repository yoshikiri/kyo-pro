#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;

  int ans = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x * x + y * y <= (ll)d * d) ++ans;
  }
  cout << ans << endl;
  return 0;
}
