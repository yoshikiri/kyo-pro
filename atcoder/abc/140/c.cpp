#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int b[n - 1];
  rep(i, n - 1) cin >> b[i];
  int a[n];
  rep(i, n) {
    if (i == 0)
      a[i] = b[i];
    else if (i == n - 1)
      a[i] = b[i - 1];
    else
      a[i] = min(b[i - 1], b[i]);
  }
  int ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;
  return 0;
}
