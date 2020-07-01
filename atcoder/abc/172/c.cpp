#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], b[m];
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vector<ll> sa(n + 1);
  rep(i, n) sa[i + 1] = sa[i] + a[i];
  vector<ll> sb(m + 1);
  rep(i, m) sb[i + 1] = sb[i] + b[i];

  int ans = 0;
  rep(i, n + 1) {
    int now = i;
    ll res = k - sa[i];
    if (res < 0) continue;
    int idx = upper_bound(sb.begin(), sb.end(), res) - sb.begin();
    now += idx - 1;
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
