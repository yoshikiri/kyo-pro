#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int d[n];
  rep(i, n) cin >> d[i];

  int ans = 0;
  rep(i, n) {
    rep(j, i) { ans += d[i] * d[j]; }
  }

  cout << ans << endl;
  return 0;
}
