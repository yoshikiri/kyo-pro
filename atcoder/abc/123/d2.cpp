#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);

  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  a.push_back(-1e17);
  b.push_back(-1e17);
  c.push_back(-1e17);
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  priority_queue<pair<ll, tuple<int, int, int>>> pq;
  pq.push({a[0] + b[0] + c[0], make_tuple(0, 0, 0)});

  vector<ll> ans;
  set<tuple<int, int, int>> used;
  used.insert({0, 0, 0});

  while ((int)ans.size() < k) {
    auto u = pq.top();
    pq.pop();

    ans.push_back(u.first);
    auto v = u.second;

    for (int i = 0; i < 3; ++i) {
      int na = get<0>(v) + (i == 0);
      int nb = get<1>(v) + (i == 1);
      int nc = get<2>(v) + (i == 2);
      if (used.find(make_tuple(na, nb, nc)) == used.end()) {
        used.insert(make_tuple(na, nb, nc));
        pq.push({a[na] + b[nb] + c[nc], make_tuple(na, nb, nc)});
      }
    }
  }

  rep(i, k) cout << ans[i] << endl;
  return 0;
}
