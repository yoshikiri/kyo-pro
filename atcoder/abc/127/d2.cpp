#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<P> d(m);
  rep(i, m) { cin >> d[i].second >> d[i].first; }

  sort(a.begin(), a.end());
  sort(d.rbegin(), d.rend());

  int idx = 0;
  rep(i, m) {
    rep(j, d[i].second) {
      if (idx >= n) break;
      if (a[idx] < d[i].first) {
        a[idx] = d[i].first;
        ++idx;
      } else {
        break;
      }
    }
  }

  ll ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;

  return 0;
}
