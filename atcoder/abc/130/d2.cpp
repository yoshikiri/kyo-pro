#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  ll k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];

  ll sum = 0, ans = 0;
  int r = 0;
  rep(l, n) {
    while (r < n && sum + a[r] < k) {
      sum += a[r];
      ++r;
    }
    ans += r - l;
    sum -= a[l];
  }
  ans = (ll)n * (n + 1) / 2 - ans;
  cout << ans << endl;
  return 0;
}
