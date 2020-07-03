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
  rep(i, n) rep(j, i) {
    int dist = 0;
    rep(k, d) { dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]); }

    bool ok = false;
    for (int k = 1; k * k <= dist; ++k) {
      if (k * k == dist) {
        ok = true;
        break;
      }
    }
    if (ok) ++ans;
  }

  cout << ans << endl;
  return 0;
}
