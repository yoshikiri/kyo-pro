#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int l[n], r[n];
  l[0] = r[n - 1] = 0;
  rep(i, n - 1) l[i + 1] = gcd(l[i], a[i]);
  for (int i = n - 1; i >= 1; --i) r[i - 1] = gcd(r[i], a[i]);

  int ans = 1;
  rep(i, n) ans = max(ans, gcd(l[i], r[i]));
  cout << ans << endl;

  return 0;
}
