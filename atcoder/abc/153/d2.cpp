#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll h;
  cin >> h;
  int cnt = 0;
  while (h > 1) {
    h /= 2;
    ++cnt;
  }

  ll ans = 1;
  rep(i, cnt + 1) ans *= 2;
  cout << ans - 1 << endl;
  return 0;
}
