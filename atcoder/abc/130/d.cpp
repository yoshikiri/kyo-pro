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

  int r = 0;
  ll sum = 0;
  ll ans = 0;
  rep(l, n) {
    while (sum < k && r < n) {
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
