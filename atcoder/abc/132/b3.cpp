#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int p[n];
  rep(i, n) cin >> p[i];
  int ans = 0;
  rep(i, n - 2) {
    bool x = (p[i + 1] != min(p[i], min(p[i + 1], p[i + 2])));
    bool y = (p[i + 1] != max(p[i], max(p[i + 1], p[i + 2])));
    if (x && y) ++ans;
  }
  cout << ans << endl;
  return 0;
}
