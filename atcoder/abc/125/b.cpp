#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int v[n], c[n];
  rep(i, n) cin >> v[i];
  rep(i, n) cin >> c[i];

  vector<int> r(n);
  rep(i, n) r[i] = v[i] - c[i];
  sort(r.rbegin(), r.rend());
  int ans = 0;
  rep(i, n) {
    if (r[i] > 0)
      ans += r[i];
    else
      break;
  }
  cout << ans << endl;
  return 0;
}
