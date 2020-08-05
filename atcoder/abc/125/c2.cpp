#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  vector<int> l(n + 1), r(n + 1);
  rep(i, n) {
    l[i + 1] = gcd(l[i], a[i]);
    r[i + 1] = gcd(r[i], a[n - 1 - i]);
  }

  int ans = 0;
  rep(i, n) { ans = max(ans, gcd(l[i], r[n - 1 - i])); }
  cout << ans << endl;

  return 0;
}
