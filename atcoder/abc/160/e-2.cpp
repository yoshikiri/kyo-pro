#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  vector<int> p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];

  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());

  vector<int> s;
  rep(i, x) s.push_back(p[i]);
  rep(i, y) s.push_back(q[i]);
  rep(i, c) s.push_back(r[i]);

  sort(s.rbegin(), s.rend());

  ll ans = 0;
  rep(i, x + y) { ans += s[i]; }

  cout << ans << '\n';

  return 0;
}
