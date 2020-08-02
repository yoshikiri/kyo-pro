#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  int ans = 1001001001;
  rep(i, 2) {
    int now = 0;
    rep(j, s.size()) {
      if ((j % 2 == 0) && ((s[j] - '0') != i)) ++now;
      if ((j % 2 == 1) && ((s[j] - '0') == i)) ++now;
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
