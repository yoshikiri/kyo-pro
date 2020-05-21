#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int ave = accumulate(a, a + n, 0) / n;

  int c1 = 0;
  rep(i, n) { c1 += (ave - a[i]) * (ave - a[i]); }
  int c2 = 0;
  rep(i, n) { c2 += (ave + 1 - a[i]) * (ave + 1 - a[i]); }

  cout << min(c1, c2) << '\n';
  return 0;
}
