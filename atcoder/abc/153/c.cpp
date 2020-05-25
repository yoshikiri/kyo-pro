#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int h[n];
  rep(i, n) cin >> h[i];

  sort(h, h + n);

  ll ans = 0;
  for (int i = 0; i < n - k; ++i) {
    ans += h[i];
  }

  cout << ans << endl;
  return 0;
}
