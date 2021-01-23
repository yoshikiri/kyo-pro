#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  map<int, ll> mp;
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    mp[a] += c;
    mp[b + 1] -= c;
  }
  ll ans = 0;
  ll s = 0;
  int pre = 0;
  for (auto p : mp) {
    ans += min<ll>(d, s) * (p.first - pre);
    s += p.second;
    pre = p.first;
  }
  cout << ans << endl;
  return 0;
}
