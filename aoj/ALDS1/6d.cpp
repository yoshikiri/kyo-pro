#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  int w[n], a[n];
  rep(i, n) {
    std::cin >> w[i];
    a[i] = w[i];
  }

  std::sort(w, w + n);

  int sum = 0;
  rep(i, n) {
    int v = a[i];
    if (w[i] != v)
      sum += v;
  }

  std::cout << sum << '\n';
  return 0;
}
