#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  ll ans = 1000;
  int i = 0, s = 0;
  while (i < n - 1) {
    while (i + 1 < n && a[i] >= a[i + 1]) ++i;
    s = a[i];
    while (i + 1 < n && a[i] <= a[i + 1]) ++i;

    ll x = ans / s;
    ans += (ll)(a[i] - s) * x;
  }
  cout << ans << endl;

  return 0;
}
