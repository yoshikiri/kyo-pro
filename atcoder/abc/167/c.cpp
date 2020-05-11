#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  int a[n][m], c[n];
  rep(i, n) {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  int p[n];
  rep(i, n) p[i] = 0;

  vector<int> ok;

  for (int i = 0; i < (1 << n); ++i) {
    bitset<12> choise(i);
    int sum = 0;
    int score[m];
    rep(j, m) score[j] = 0;

    for (int j = 0; j < n; ++j) {
      if (choise.test(j)) {
        sum += c[j];
        rep(l, m) { score[l] += a[j][l]; }
      }
    }

    bool isOk = true;
    rep(j, m) {
      if (score[j] < x) isOk = false;
    }
    if (isOk) ok.push_back(sum);
  }

  if (ok.size() == 0) {
    cout << "-1" << '\n';
    return 0;
  }

  int ans = ok[0];
  rep(i, ok.size()) { ans = min(ans, ok[i]); }
  cout << ans << '\n';

  return 0;
}
