#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  rep(i, n) cin >> a[i];
  a[n] = a[0];
  ll sum = 0;
  rep(i, n) sum += a[i];
  ll x = 0;
  rep(i, n) {
    if (i & 1)
      x -= a[i];
    else
      x += a[i];
  }
  cout << x << endl;
  rep(i, n - 1) {
    x = 2 * a[i] - x;
    cout << x << endl;
  }
  return 0;
}
