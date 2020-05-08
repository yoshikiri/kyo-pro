#include <iostream>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n, a, b;
  std::cin >> n >> a >> b;

  ll c = n / (a + b);
  ll ans = a * c + std::min(a, n % (a + b));

  std::cout << ans << '\n';

  return 0;
}
