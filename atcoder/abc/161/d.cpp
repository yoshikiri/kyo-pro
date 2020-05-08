#include <iostream>
#include <queue>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k;
  std::cin >> k;

  std::queue<ll> q;

  for (int i = 1; i <= 9; ++i) q.push(i);

  ll x = 1;
  for (int i = 0; i < k; ++i) {
    x = q.front();
    q.pop();

    if (x % 10 != 0) q.push(10 * x + (x % 10) - 1);
    q.push(10 * x + x % 10);
    if (x % 10 != 9) q.push(10 * x + (x % 10) + 1);
  }

  std::cout << x << '\n';

  return 0;
}
