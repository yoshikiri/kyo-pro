// 16:32 - 17:04
#include <iostream>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll f(ll x, ll c, ll d) {
  ll res = x;
  res -= x / c;
  res -= x / d;
  res += x / lcm(c, d);
  return res;
}

int main() {
  ll a, b, c, d;
  std::cin >> a >> b >> c >> d;

  ll ans = f(b, c, d) - f(a - 1, c, d);
  std::cout << ans << '\n';

  return 0;
}
