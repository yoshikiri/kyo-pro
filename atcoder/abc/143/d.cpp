#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end());

  ll ans = 0;
  rep(i, n) rep(j, i) {
    int d = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin() - (i + 1);
    if (d > 0) ans += d;
  }

  cout << ans << endl;
  return 0;
}
