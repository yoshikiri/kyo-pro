#include <iostream>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  std::cin >> n >> m;
  int a[m];
  rep(i, m) std::cin >> a[i];

  int sum = std::accumulate(a, a + m, 0);
  int ans = n - sum;

  if (ans < 0) {
    std::cout << -1 << '\n';
  } else {
    std::cout << ans << '\n';
  }

  return 0;
}
