#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();

  int ans = n;
  rep(i, 2) {
    int now = 0;
    char c = i + '0';
    rep(j, n) {
      // if (j % 2 == 0 && s[j] != c) ++now;
      // if (j % 2 != 0 && s[j] == c) ++now;
      if ((j % 2 == 0) ^ (s[j] == c)) ++now;
    }
    ans = min(ans, now);
  }
  cout << ans << endl;

  return 0;
}
