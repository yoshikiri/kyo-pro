#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  int x[n][d];
  rep(i, n) { rep(j, d) cin >> x[i][j]; }

  auto f = [](int n) {
    for (int i = 1; i * i <= n; ++i) {
      if (i * i == n) return true;
    }
    return false;
  };

  int ans = 0;
  rep(i, n) rep(j, i) {
    int d2 = 0;
    rep(k, d) {
      int dx = x[i][k] - x[j][k];
      d2 += dx * dx;
    }
    if (f(d2)) ++ans;
  }

  cout << ans << endl;
  return 0;
}
