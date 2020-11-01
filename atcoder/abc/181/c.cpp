#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  rep(i, n) cin >> x[i] >> y[i];

  bool ans = false;
  rep(i, n) rep(j, i) rep(k, j) {
    int dx1 = x[i] - x[j];
    int dy1 = y[i] - y[j];
    int dx2 = x[j] - x[k];
    int dy2 = y[j] - y[k];
    if (dx1 * dy2 == dx2 * dy1) ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
