#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int mx = 0;
  rep(i, n) mx = max(mx, a[i]);
  int k = 0;
  while (mx > 0) {
    mx /= 2;
    ++k;
  }

  int ans[n][k];

  rep(i, k) {
    vector<int> same(n);
    int z = a[0] >> i & 1;
    rep(j, n) { same[j] = z == (a[j] >> i & 1); }
    int sum = 0;
    for (int j = 1; j < n; ++j) sum += same[j];
    int x = (sum % 2 == z % 2);
    rep(j, n) {
      if (same[j])
        ans[j][i] = x;
      else
        ans[j][i] = (x + 1) % 2;
    }
  }

  rep(i, n) {
    int b = 0;
    rep(j, k) {
      int res = 1;
      rep(r, j) res *= 2;
      b += res * ans[i][j];
    }
    cout << b;
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
