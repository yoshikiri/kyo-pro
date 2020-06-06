#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<vector<P>> v(n, vector<P>());
  rep(i, n) {
    int a;
    cin >> a;
    rep(j, a) {
      int x, y;
      cin >> x >> y;
      --x;
      v[i].push_back({x, y});
    }
  }

  int ans = 0;
  rep(s, 1 << n) {
    vector<int> d(n);
    rep(i, n) { d[i] = s >> i & 1; }

    bool ok = true;
    rep(i, n) {
      if (d[i] == 0) continue;
      for (auto p : v[i]) {
        int x = p.first, y = p.second;
        if (d[x] != y) {
          ok = false;
          break;
        }
      }
    }

    if (!ok) continue;
    int now = 0;
    rep(i, n) now += d[i];
    ans = max(ans, now);
  }

  cout << ans << endl;

  return 0;
}
