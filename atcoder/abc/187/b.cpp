#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  rep(i, n) cin >> x[i] >> y[i];
  int ans = 0;
  rep(i, n) rep(j, i) {
    if ((abs(y[i] - y[j]) <= abs(x[i] - x[j]))) ++ans;
  }
  cout << ans << endl;
  return 0;
}
