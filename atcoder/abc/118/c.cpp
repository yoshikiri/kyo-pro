#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];

  while (a.size() > 1) {
    for (int i = a.size() - 1; i >= 0; --i) {
      if (a[i] == 0) a.erase(a.begin() + i);
    }

    int minIdx = std::distance(a.begin(), std::min_element(a.begin(), a.end()));
    rep(i, n) {
      if (i != minIdx) { a[i] %= a[minIdx]; }
    }
  }

  rep(i, n) {
    if (a[i] != 0) { std::cout << a[i] << '\n'; }
  }

  return 0;
}
