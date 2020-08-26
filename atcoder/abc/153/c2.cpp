#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  sort(h.begin(), h.end());
  ll ans = 0;
  rep(i, n - k) ans += h[i];
  cout << ans << endl;
  return 0;
}
