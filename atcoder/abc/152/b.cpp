#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;

  string ans = "";
  if (a > b) {
    rep(i, a) ans += b + '0';
  } else {
    rep(i, b) ans += a + '0';
  }

  cout << ans << endl;
  return 0;
}
