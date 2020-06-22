#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1], p[n];
  a[0] = 1001001001;
  rep(i, n) {
    cin >> p[i];
    a[i + 1] = min(a[i], p[i]);
  }

  int ans = 0;
  rep(i, n) {
    if (p[i] <= a[i]) ++ans;
  }
  cout << ans << endl;
  return 0;
}
