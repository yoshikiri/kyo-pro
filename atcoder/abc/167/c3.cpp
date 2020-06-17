#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int c[n];
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  int ans = 1001001001;
  rep(s, 1 << n) {
    int now = 0;
    vector<int> d(m);
    rep(i, n) {
      if (s >> i & 1) {
        rep(j, m) d[j] += a[i][j];
        now += c[i];
      }
    }

    bool ok = true;
    rep(i, m) if (d[i] < x) ok = false;
    if (ok) ans = min(ans, now);
  }

  if (ans == 1001001001) ans = -1;
  cout << ans << endl;
  return 0;
}
