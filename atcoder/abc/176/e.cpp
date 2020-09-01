#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  set<P> s;
  vector<int> c1(h), c2(w);
  rep(mi, m) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    ++c1[i], ++c2[j];
    s.insert({i, j});
  }

  ll ans = 0;
  int mx1 = 0, mx2 = 0;
  rep(i, h) mx1 = max(mx1, c1[i]);
  rep(i, w) mx2 = max(mx2, c2[i]);

  int cnt1 = 0;
  rep(i, h) cnt1 += (c1[i] == mx1);
  int cnt2 = 0;
  rep(i, w) cnt2 += (c2[i] == mx2);

  ll e = (ll)cnt1 * cnt2;
  for (auto p : s) {
    if (c1[p.first] == mx1 && c2[p.second] == mx2) --e;
  }

  ans = (ll)mx1 + mx2;
  if (e == 0) --ans;
  cout << ans << endl;
  return 0;
}
