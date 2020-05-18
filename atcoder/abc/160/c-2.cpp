#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k, n;
  cin >> k >> n;

  int a[n + 1];
  rep(i, n) cin >> a[i];
  a[n] = a[0] + k;

  int l = 0;
  rep(i, n) { l = max(l, a[i + 1] - a[i]); }

  int ans = k - l;
  cout << ans << '\n';
  return 0;
}
