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

  vector<ll> ab(x * y);
  rep(i, x) rep(j, y) ab[i * y + j] = a[i] + b[j];
  sort(ab.rbegin(), ab.rend());

  vector<ll> abc(min(k, x * y) * z);
  rep(i, min(k, x * y)) rep(j, z) abc[i * z + j] = ab[i] + c[j];

  sort(abc.rbegin(), abc.rend());
  rep(i, k) cout << abc[i] << endl;
  return 0;
}
