#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  vector<ll> e;
  rep(i, x) rep(j, y) e.push_back(a[i] + b[j]);
  sort(e.rbegin(), e.rend());

  vector<ll> f;
  rep(i, min(x * y, k)) rep(j, z) f.push_back(e[i] + c[j]);
  sort(f.rbegin(), f.rend());

  rep(i, k) cout << f[i] << endl;

  return 0;
}
