#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int v[n], c[n];
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];

  int ans = 0;
  rep(i, n) {
    if (v[i] - c[i] > 0) ans += v[i] - c[i];
  }
  cout << ans << endl;
  return 0;
}
