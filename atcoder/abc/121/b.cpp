#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int b[m];
  rep(i, m) cin >> b[i];

  int a[m];
  int ans = 0;
  rep(i, n) {
    rep(j, m) cin >> a[j];
    int sum = 0;
    rep(j, m) sum += a[j] * b[j];
    sum += c;
    if (sum > 0) ++ans;
  }

  cout << ans << endl;
  return 0;
}
