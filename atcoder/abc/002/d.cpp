#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  set<int> to[n];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    to[x].insert(y);
    to[y].insert(x);
  }

  int ans = 1;
  rep(s, 1 << n) {
    vector<int> h;
    bool ok = true;
    rep(i, n) {
      if (s >> i & 1) {
        for (auto u : h) {
          if (to[i].find(u) == to[i].end()) ok = false;
        }
        if (!ok) break;
        h.push_back(i);
      }
    }
    if (ok) ans = max(ans, (int)h.size());
  }
  cout << ans << endl;
  return 0;
}
