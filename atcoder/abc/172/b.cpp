#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int ans = 0;
  rep(i, n) {
    if (s[i] != t[i]) ++ans;
  }
  cout << ans << endl;
  return 0;
}
