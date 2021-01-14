#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    bool ok = true;
    for (auto base : {8, 10}) {
      int t = i;
      while (t > 0) {
        if (t % base == 7) ok = false;
        t /= base;
      }
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
  return 0;
}
