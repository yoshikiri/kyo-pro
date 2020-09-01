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
  ll ans = 0;
  rep(i, n) {
    ans += max((mx - a[i]), 0);
    mx = max(mx, a[i]);
  }
  cout << ans << endl;
  return 0;
}
