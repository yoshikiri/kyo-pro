#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  int ans = t.size();
  rep(i, s.size() - t.size() + 1) {
    int now = 0;
    rep(j, t.size()) {
      if (s[i + j] != t[j]) ++now;
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
