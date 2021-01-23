#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0;
  rep(i, n) { ans += a[i] * b[i]; }
  cout << (ans == 0 ? "Yes" : "No") << endl;
  return 0;
}
