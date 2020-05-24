#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a, b;
  rep(i, n) {
    int x;
    cin >> x;
    if (x >= 0)
      a.push_back(x);
    else
      b.push_back(x);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int d;
  for (int i = 0; i <= k; ++i) {
    if (i * (i + 1) / 2 + 1 <= k && k <= (i + 1) * (i + 2) / 2) d = i;
  }

  // for (int i = (int)sqrt(2 * k - 2); i <= (int)sqrt(2 * k); ++i) {
  //   if (i * (i + 1) <= 2 * k - 1 && (i + 1) * (i + 2) >= 2 * k) d = i;
  // }

  cout << d << endl;

  ll ans = (ll)1001001001 * 1001001001;

  for (int i = 0; i <= d; ++i) {
    ans = ans <= a[i] * b[d - i] ? ans : a[i] * b[d - i];
  }

  cout << ans << '\n';

  return 0;
}
