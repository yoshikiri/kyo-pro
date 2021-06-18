#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll l = 1; l < 10010010; ++l) {
    ll a = l * (l - 1) / 2;
    ll b = n - a;
    if (b < 0) continue;
    if (b % l != 0) continue;
    if (b / l > 1)
      ans += 2;
    else
      ++ans;
  }

  cout << ans << endl;
  return 0;
}
