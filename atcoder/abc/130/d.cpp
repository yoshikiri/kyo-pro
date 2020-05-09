#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  ll k;
  cin >> n >> k;

  int a[n];
  rep(i, n) cin >> a[i];

  ll ans = 0, sum = 0;
  int r = 0;
  for (int l = 0; l < n; ++l) {
    while (sum < k) {
      if (r >= n) break;
      sum += a[r];
      ++r;
    }

    if (sum < k) break;

    ans += n - r + 1;
    sum -= a[l];
  }

  cout << ans << endl;

  return 0;
}
