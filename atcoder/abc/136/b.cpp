#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  int ori = n;
  int d = 0;
  while (n > 0) {
    n /= 10;
    ++d;
  }

  int ans = 0;
  for (int i = 1; i <= d; ++i) {
    if (i % 2 == 0) continue;
    if (i == d) {
      int s = 1;
      rep(j, i - 1) s *= 10;
      ans += ori - s + 1;
    } else {
      int s = 1;
      rep(j, i - 1) s *= 10;
      ans += 9 * s;
    }
  }

  cout << ans << endl;
  return 0;
}
