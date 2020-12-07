#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int main() {
  string s, t;
  cin >> s >> t;

  map<char, vector<int>> mp;
  int ns = s.size();
  rep(i, ns) mp[s[i]].push_back(i);

  int nt = t.size();
  ll ans = 0;
  int cur = 0;
  rep(i, nt) {
    char c = t[i];
    if (!mp.count(c)) {
      cout << -1 << endl;
      return 0;
    }

    auto it = lower_bound(all(mp[c]), cur);
    if (it == mp[c].end()) {
      ans += ns;
      cur = mp[c][0] + 1;
    } else {
      cur = *it + 1;
    }
  }
  ans += cur;
  cout << ans << endl;
  return 0;
}
