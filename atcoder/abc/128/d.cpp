#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int v[n];
  rep(i, n) cin >> v[i];

  int ans = 0;

  for (int a = 0; a <= min(n, k); ++a) {
    for (int b = 0; b <= min(n, k) - a; ++b) {
      vector<int> g;
      int now = 0;
      rep(i, a) {
        g.push_back(v[i]);
        now += v[i];
      }
      rep(i, b) {
        g.push_back(v[n - i - 1]);
        now += v[n - i - 1];
      }
      sort(g.begin(), g.end());

      int res = k - (a + b);
      int m = g.size();
      rep(i, min(res, m)) {
        if (g[i] > 0) break;
        now -= g[i];
      }

      ans = max(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}
