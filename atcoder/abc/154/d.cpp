#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int d[n + 1];
  d[0] = 0;
  for (int i = 0; i < n; ++i) {
    d[i + 1] = d[i] + a[i];
  }

  double ans = 0;
  rep(i, n - k + 1) {
    double now = (d[i + k] - d[i] + k) / 2.0;
    ans = max(ans, now);
  }

  printf("%.10f\n", ans);

  return 0;
}
