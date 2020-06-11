#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int f(int n) {
  if (n < 0) return 0;
  if (n == 0 || n == 1) return 1;
  return n * f(n - 1);
}

int main() {
  int n;
  cin >> n;

  P p[n];
  rep(i, n) cin >> p[i].first >> p[i].second;

  // double d[n][n];
  // rep(i, n) rep(j, n) {
  //   double dx = p[i].first - p[j].first;
  //   double dy = p[i].second - p[j].second;
  //   d[i][j] = sqrt(dx * dx + dy * dy);
  // }

  // double ans = 0;
  // rep(i, n) rep(j, n) { ans += d[i][j]; }

  // printf("%.15f\n", f(n - 1) * ans / f(n));

  auto d = [&](int i, int j) {
    int dx = p[i].first - p[j].first;
    int dy = p[i].second - p[j].second;
    return sqrt(dx * dx + dy * dy);
  };

  vector<int> a(n);
  rep(i, n) a[i] = i;
  int cnt = 0;
  double len = 0;
  do {
    rep(i, n - 1) { len += d(a[i], a[i + 1]); }
    ++cnt;
  } while (next_permutation(a.begin(), a.end()));

  double ans = len / cnt;
  printf("%.15f\n", ans);

  return 0;
}
