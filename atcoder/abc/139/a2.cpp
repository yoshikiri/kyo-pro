#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  int n = s.size();
  rep(i, n) ans += (s[i] == t[i]);
  cout << ans << endl;
  return 0;
}
