#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size();

  map<char, vector<int>> idx;
  rep(i, n) { idx[s[i]].push_back(i); }
  rep(i, n) { idx[s[i]].push_back(i + n); }

  int cur = -1;
  ll ans = 0;
  rep(i, t.size()) {
    if (idx.count(t[i]) == 0) {
      cout << "-1" << endl;
      return 0;
    }

    cur = *lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
    if (cur >= (int)n - 1) {
      ans += n;
      cur -= n;
    }
  }

  cout << ans + cur + 1 << endl;
  return 0;
}
