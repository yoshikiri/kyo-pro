// 16:32 - 17:04
#include <iostream>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  ll a, b, c, d;
  std::cin >> a >> b >> c >> d;

  ll minc = (a % c == 0) ? a : a + (c - a % c);
  ll maxc = b - b % c;
  ll mind = (a % d == 0) ? a : a + (d - a % d);
  ll maxd = b - b % d;
  ll cd = c * d / gcd(c, d);
  ll mincd = (a % cd == 0) ? a : a + (cd - a % cd);
  ll maxcd = b - b % cd;

  ll sum = b - a + 1;
  ll sumc = (maxc - minc) / c + 1;
  ll sumd = (maxd - mind) / d + 1;
  ll sumcd = (maxcd - mincd) / cd + 1;

  ll ans = sum - sumc - sumd + sumcd;
  std::cout << ans << '\n';

  return 0;
}
