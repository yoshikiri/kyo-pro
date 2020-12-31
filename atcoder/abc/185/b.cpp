#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  int a[m], b[m];
  rep(i, m) cin >> a[i] >> b[i];

  int now = n, s = 0;
  rep(i, m) {
    now -= a[i] - s;
    if (now <= 0) {
      cout << "No" << endl;
      return 0;
    }
    now += b[i] - a[i];
    now = min(n, now);
    s = b[i];
  }
  bool ans = now - (t - s) > 0;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
