#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int b[m];
  rep(i, m) cin >> b[i];

  int ans = 0;
  rep(i, n) {
    int a[m];
    rep(j, m) cin >> a[j];
    int sum = 0;
    rep(j, m) sum += a[j] * b[j];
    if (sum + c > 0) ++ans;
  }

  cout << ans << endl;
  return 0;
}
