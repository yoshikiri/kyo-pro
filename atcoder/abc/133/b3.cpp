#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  int x[n][d];
  rep(i, n) rep(j, d) cin >> x[i][j];

  int ans = 0;
  rep(i, n) {
    rep(j, i) {
      int d2 = 0;
      rep(k, d) d2 += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      int d = sqrt(d2) + 0.5;
      if (d * d == d2) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
