#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  vector<int> ans(n + 1);

  for (ll x = 1; x * x <= n; ++x) {
    for (ll y = 1; y * y <= n; ++y) {
      for (ll z = 1; z * z <= n; ++z) {
        ll w = x * x + y * y + z * z + x * y + y * z + z * x;
        if (w > n) continue;
        ++ans[w];
      }
    }
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
  return 0;
}
