#include <iostream>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll x;
  std::cin >> x;

  ll sum = 100;
  ll cnt = 0;
  while (sum < x) {
    sum += sum / 100;
    cnt++;
  }

  std::cout << cnt << '\n';
  return 0;
}
