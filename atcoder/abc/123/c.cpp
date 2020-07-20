#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;
  ll a[5];
  rep(i, 5) cin >> a[i];

  ll mn = 1e15 + 1;
  rep(i, 5) mn = min(mn, a[i]);

  ll g = (n + mn - 1) / mn;
  cout << 5 + g - 1 << endl;
  return 0;
}
