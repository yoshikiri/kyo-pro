#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

P f(int x) {
  int a = x % 10;
  int b;
  while (x > 0) {
    b = x;
    x /= 10;
  }

  return P(a, b);
}

int main() {
  int n;
  cin >> n;

  int c[10][10];
  rep(i, 10) rep(j, 10) c[i][j] = 0;

  for (int i = 1; i <= n; ++i) {
    P p = f(i);
    ++c[p.first][p.second];
  }

  int ans = 0;
  rep(i, 10) rep(j, 10) ans += c[i][j] * c[j][i];

  cout << ans << endl;
  return 0;
}
