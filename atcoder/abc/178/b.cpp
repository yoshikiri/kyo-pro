#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = max(a * c, max(a * d, max(b * c, b * d)));
  cout << ans << endl;
  return 0;
}
