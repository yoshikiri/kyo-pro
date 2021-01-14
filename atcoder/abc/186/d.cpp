#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());

  ll ans = 0;
  rep(i, n) { ans += (ll)(2 * i - (n - 1)) * v[i]; }
  cout << ans << endl;
  return 0;
}
