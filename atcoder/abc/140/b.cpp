#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n], b[n], c[n - 1];
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n - 1) cin >> c[i];

  int ans = 0;
  int pre = -2;
  rep(i, n) {
    int id = a[i] - 1;
    ans += b[id];
    if (pre == id - 1) ans += c[pre];
    pre = id;
  }
  cout << ans << endl;
  return 0;
}
