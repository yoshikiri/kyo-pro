#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> m >> m;
  int l = 0;
  int r = 1001001;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    l = max(l, x);
    r = min(r, y);
  }

  int d = r - l + 1;
  d = max(d, 0);
  cout << d << endl;
  return 0;
}
