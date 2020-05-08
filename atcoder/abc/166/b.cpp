#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);

  int d, e;
  rep(i, k) {
    std::cin >> d;
    rep(j, d) {
      std::cin >> e;
      --e;
      ++a[e];
    }
  }

  int cnt = 0;
  rep(i, n) if (a[i] == 0)++ cnt;

  std::cout << cnt << '\n';

  return 0;
}
