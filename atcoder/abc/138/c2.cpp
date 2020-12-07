#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());

  double d = 1;
  rep(j, n - 1) d *= 2;
  double ans = (v[0] + v[1]) / d;
  rep(i, n - 2) {
    double d = 1;
    rep(j, n - 2 - i) d *= 2;
    ans += v[i + 2] / d;
  }

  printf("%.15f\n", ans);
  return 0;
}
