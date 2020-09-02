#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  ll a[n];
  rep(i, n) cin >> a[i];

  rep(i, n) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll x = 1;
  ll lim = 1e18;
  rep(i, n) {
    if (a[i] > lim / x) {
      cout << -1 << endl;
      return 0;
    }
    x *= a[i];
  }
  cout << x << endl;
  return 0;
}
