#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll g(ll x, int i) {
  ll d = pow(2, i + 1);
  ll a = x % d;
  ll b = x / d;
  return b * (d / 2) + max(0LL, a - (d / 2 - 1));
}

ll h(ll x, ll y, int i) {
  ll c = g(y, i) - g(x, i);
  if (c & 1) return pow(2, i);
  return 0;
}

ll calc(ll x) {
  ++x;
  ll ans = 0;
  rep(i, 50) {
    ll loop = (1LL << (i + 1));
    ll cnt = (x / loop) * (loop / 2);
    cnt += max(0LL, x % loop - loop / 2);

    if (cnt & 1) ans += 1LL << i;
  }
  return ans;
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = calc(b) ^ calc(a - 1);
  cout << ans << endl;

  // ll ans = 0;
  // rep(i, 45) { ans += h(a - 1, b, i); }
  // cout << ans << endl;
  return 0;
}
