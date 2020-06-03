#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  string ans = "";
  rep(i, n) {
    ans += s[i];
    ans += t[i];
  }

  cout << ans << endl;
  return 0;
}
