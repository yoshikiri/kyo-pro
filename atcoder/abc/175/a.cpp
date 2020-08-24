#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0, now = 0;
  rep(i, n) {
    if (s[i] == 'R')
      ++now;
    else {
      ans = max(ans, now);
      now = 0;
    }
  }
  ans = max(ans, now);
  cout << ans << endl;
  return 0;
}
