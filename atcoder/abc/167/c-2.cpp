#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  int a[n][m];
  int c[n];

  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  int ans = INF;
  rep(s, 1 << n) {
    int sum = 0;
    int score[m];
    rep(i, m) score[i] = 0;

    rep(i, n) {
      if (s >> i & 1) {
        sum += c[i];
        rep(j, m) score[j] += a[i][j];
      }

      bool ok = true;
      rep(i, m) if (score[i] < x) ok = false;

      if (ok) ans = min(ans, sum);
    }
  }

  if (ans == INF)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
  return 0;
}
