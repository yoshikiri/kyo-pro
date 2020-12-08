#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;
  int ns = s.size();
  int nt = t.size();

  vector<vector<int>> v(26, vector<int>());
  rep(i, ns) v[s[i] - 'a'].push_back(i);
  rep(i, ns) v[s[i] - 'a'].push_back(i + ns);

  ll ans = 0;
  int p = 0;
  rep(i, nt) {
    int x = t[i] - 'a';
    if (v[x].empty()) {
      cout << -1 << endl;
      return 0;
    }
    p = *lower_bound(v[x].begin(), v[x].end(), p) + 1;
    if (p >= ns) {
      p -= ns;
      ans += ns;
    }
  }
  ans += p;
  cout << ans << endl;
  return 0;
}
