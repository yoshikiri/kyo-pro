#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int a[m], b[m];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    a[i] = x - 1;
    b[i] = y - 1;
  }
  int k;
  cin >> k;
  int c[k], d[k];
  rep(i, k) {
    int x, y;
    cin >> x >> y;
    c[i] = x - 1;
    d[i] = y - 1;
  }

  int ans = 0;
  rep(s, 1 << 16) {
    int e[n] = {0};
    rep(i, k) {
      if (s >> i & 1)
        ++e[c[i]];
      else
        ++e[d[i]];
    }

    int sum = 0;
    rep(i, m) {
      if (e[a[i]] >= 1 && e[b[i]] >= 1) ++sum;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
