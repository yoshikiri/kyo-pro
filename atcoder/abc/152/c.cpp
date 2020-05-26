#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int p[n];
  rep(i, n) { cin >> p[i]; }

  int a[n];
  a[0] = 1001001001;
  for (int i = 0; i < n - 1; ++i) {
    a[i + 1] = min(a[i], p[i]);
  }

  int ans = 0;
  rep(i, n) {
    if (p[i] <= a[i]) ++ans;
  }
  cout << ans << endl;

  return 0;
}
