#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int ans = 0;
  ans += min(k, a);
  k -= min(k, a);
  k -= min(k, b);
  ans -= min(k, c);

  cout << ans << endl;
  return 0;
}
