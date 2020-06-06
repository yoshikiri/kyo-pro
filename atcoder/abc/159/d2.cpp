#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll choose(ll n) {
  if (n <= 0) return 0;
  return n * (n - 1) / 2;
}

int main() {
  int n;
  cin >> n;

  int a[n];
  map<int, int> mp;
  rep(i, n) {
    cin >> a[i];
    ++mp[a[i]];
  }

  ll mx = 0;
  for (auto p : mp) mx += choose(p.second);

  rep(i, n) {
    int k = mp[a[i]];
    ll ans = mx;
    ans -= choose(k) - choose(k - 1);
    cout << ans << endl;
  }

  return 0;
}
