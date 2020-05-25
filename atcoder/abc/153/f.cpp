#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d, a;
  cin >> n >> d >> a;

  vector<P> v(n);
  rep(i, n) { cin >> v[i].first >> v[i].second; }

  sort(v.begin(), v.end());

  ll ans = 0;
  ll tot = 0;
  queue<P> q;

  rep(i, n) {
    int x = v[i].first;
    int h = v[i].second;

    while (!q.empty() && q.front().first < x) {
      P p = q.front();
      q.pop();
      tot -= p.second;
    }
    h -= tot;

    if (h > 0) {
      int s = (h + a - 1) / a;
      ans += s;
      ll damage = (ll)s * a;
      tot += damage;
      q.push({x + 2 * d, damage});
    }
  }

  cout << ans << endl;

  return 0;
}
