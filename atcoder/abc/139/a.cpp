#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  int ans = 0;
  rep(i, 3) if (s[i] == t[i])++ ans;
  cout << ans << endl;
  return 0;
}
