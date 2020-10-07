#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, x;
  cin >> n >> x;
  int l[n];
  rep(i, n) cin >> l[i];

  int d = 0, ans = 1;
  rep(i, n) {
    d += l[i];
    if (d > x) break;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
