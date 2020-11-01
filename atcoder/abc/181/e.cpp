#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n), w(m);
  rep(i, n) cin >> h[i];
  rep(i, m) cin >> w[i];

  sort(h.begin(), h.end());

  vector<ll> d(n - 1);
  rep(i, n - 1) d[i] = h[i + 1] - h[i];

  vector<ll> sa(n / 2 + 1), sb(n / 2 + 1);
  rep(i, n - 1) {
    if (i & 1)
      sb[i / 2 + 1] = sb[i / 2] + h[i + 1] - h[i];
    else
      sa[i / 2 + 1] = sa[i / 2] + h[i + 1] - h[i];
  }

  ll ans = 1e18;
  rep(i, m) {
    int idx = lower_bound(h.begin(), h.end(), w[i]) - h.begin();
    if (idx & 1) idx ^= 1;
    ll now = 0;
    now += sa[idx / 2];
    now += sb[n / 2] - sb[idx / 2];
    now += abs(h[idx] - w[i]);
    ans = min(ans, now);
  }
  cout << ans << endl;

  return 0;
}
