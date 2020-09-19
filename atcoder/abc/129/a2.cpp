#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int p, q, r;
  cin >> p >> q >> r;
  int ans = p + q + r;
  ans -= max(p, max(q, r));
  cout << ans << endl;
  return 0;
}
