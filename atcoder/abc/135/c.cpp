#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n];
  rep(i, n + 1) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ans = 0;
  rep(i, n) {
    int k = min(a[i], b[i]);
    a[i] -= k;
    ans += k;
    int s = min(a[i + 1], b[i] - k);
    a[i + 1] -= s;
    ans += s;
  }

  cout << ans << endl;
  return 0;
}
