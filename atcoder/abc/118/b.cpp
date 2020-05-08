#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  std::cin >> n >> m;

  int a[m];
  rep(i, m) a[i] = 0;

  rep(i, n) {
    int k;
    std::cin >> k;
    rep(j, k) {
      int id;
      std::cin >> id;
      id--;
      a[id]++;
    }
  }

  int cnt = 0;
  rep(i, m) {
    if (a[i] == n) cnt++;
  }
  std::cout << cnt << '\n';

  return 0;
}
