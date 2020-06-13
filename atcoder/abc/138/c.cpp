#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int v[n];
  rep(i, n) cin >> v[i];

  sort(v, v + n);
  double ans = v[0];
  rep(i, n - 1) { ans = (ans + v[i + 1]) / 2; }
  cout << ans << endl;
  return 0;
}
