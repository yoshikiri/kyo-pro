#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  if (n % 2 == 0) {
    int mn = a[n / 2 - 1] + a[n / 2];
    int mx = b[n / 2 - 1] + b[n / 2];
    ans = mx - mn + 1;
  } else {
    int mn = a[n / 2];
    int mx = b[n / 2];
    ans = mx - mn + 1;
  }
  cout << ans << endl;
  return 0;
}
