#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll sum = 0;
  rep(i, n) sum += a[i];

  set<int> ds;
  for (int i = 1; (ll)i * i <= sum; ++i) {
    if (sum % i == 0) {
      ds.insert(i);
      ds.insert(sum / i);
    }
  }

  ll ans = 1;
  for (ll x : ds) {
    ll now = 0;
    vector<ll> r(n);
    rep(i, n) r[i] = a[i] % x;
    sort(r.begin(), r.end());
    ll B = 0;
    rep(i, n) B += x - r[i];
    ll A = 0;
    now = 1e18;
    rep(i, n) {
      A += r[i];
      B -= x - r[i];
      now = min(now, max(A, B));
    }

    if (now <= k) ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}
