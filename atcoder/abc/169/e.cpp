#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  rep(i, n) cin >> a[i] >> b[i];

  sort(a, a + n);
  sort(b, b + n);

  int ans = 0;
  if (n % 2 == 1) {
    int mn = a[n / 2], mx = b[n / 2];
    ans = mx - mn + 1;
  } else {
    double mn = (a[n / 2] + a[n / 2 - 1]) / 2.0;
    double mx = (b[n / 2] + b[n / 2 - 1]) / 2.0;
    ans = (mx - mn) * 2 + 1;
  }

  cout << ans << endl;
  return 0;
}
