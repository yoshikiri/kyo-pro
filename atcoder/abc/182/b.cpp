#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  int mx = 0;
  rep(i, n) mx = max(mx, a[i]);
  int ans = 2, cnt = 0;
  for (int i = 2; i <= mx; ++i) {
    int now = 0;
    rep(j, n) {
      if (a[j] % i == 0) ++now;
    }
    if (cnt >= now) continue;
    cnt = now;
    ans = i;
  }
  cout << ans << endl;
  return 0;
}
