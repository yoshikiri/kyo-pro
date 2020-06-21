#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  rep(i, n) { cin >> x[i] >> y[i]; }

  auto f = [](int n) {
    int res = 1;
    rep(i, n) res *= i + 1;
    return res;
  };

  double ans = 0;
  rep(i, n) rep(j, n) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    double d = sqrt((dx * dx) + (dy * dy));
    ans += d;
  }

  ans *= f(n - 1);
  ans /= f(n);

  printf("%.10f\n", ans);

  return 0;
}
