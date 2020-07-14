#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int l = 1, r = n;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    if (l < x) l = x;
    if (y < r) r = y;
  }

  int ans = max(0, r - l + 1);
  cout << ans << endl;
  return 0;
}
