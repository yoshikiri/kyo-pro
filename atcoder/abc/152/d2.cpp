#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  map<P, int> mp;
  for (int i = 1; i <= n; ++i) {
    int t = i % 10;
    int h = (to_string(i))[0] - '0';
    ++mp[{h, t}];
  }

  ll ans = 0;
  for (auto p : mp) {
    int h = p.first.first;
    int t = p.first.second;
    int cnt = p.second;
    ans += (ll)cnt * mp[{t, h}];
  }

  cout << ans << endl;
  return 0;
}
