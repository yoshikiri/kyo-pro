#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end(), [](auto const &lhs, auto const &rhs) {
    ll s1 = (ll)2 * lhs.first + lhs.second;
    ll s2 = (ll)2 * rhs.first + rhs.second;
    return s1 > s2;
  });
  ll as = 0, ts = 0;
  rep(i, n) as += v[i].first;

  int ans = 0;
  rep(i, n) {
    if (as < ts) {
      ans = i;
      break;
    }
    as -= v[i].first;
    ts += v[i].first + v[i].second;
  }
  if (ans == 0) ans = 1;
  cout << ans << endl;
  return 0;
}
