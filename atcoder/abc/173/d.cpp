#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.rbegin(), a.rend());

  ll ans = a[0];
  rep(i, (n - 2) / 2) { ans += (ll)a[1 + i] * 2; }
  if (n % 2 == 1) ans += a[1 + (n - 2) / 2];
  cout << ans << endl;
  return 0;
}
