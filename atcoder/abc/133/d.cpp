#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, n) {
    if (i % 2)
      sum -= a[i];
    else
      sum += a[i];
  }

  ll x[n];
  x[0] = sum;
  rep(i, n - 1) { x[i + 1] = (ll)2 * a[i] - x[i]; }

  rep(i, n) printf("%lld%c", x[i], (i == n - 1) ? '\n' : ' ');
  return 0;
}
