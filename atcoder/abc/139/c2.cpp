#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  int ans = 0, now = 0;
  int cur = h[0];
  rep(i, n - 1) {
    if (cur >= h[i + 1]) {
      ++now;
    } else {
      ans = max(ans, now);
      now = 0;
    }
    cur = h[i + 1];
  }
  ans = max(ans, now);
  cout << ans << endl;
  return 0;
}
