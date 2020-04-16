#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int insertionSort(int *a, int n, int g) {
  int cnt = 0;
  for (int i = g; i < n; ++i) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && v < a[j]) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
  return cnt;
}

int shellSort(int *a, int n) {
  int cnt = 0;
  int m = (int)(std::log(n) / std::log(2));
  if (m <= 0)
    m = 1;
  int g[m];

  rep(i, m) { g[i] = std::pow(2, i); }

  std::cout << m << '\n';
  rep(i, m) {
    std::cout << g[m - 1 - i];
    if (i == m - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }

  rep(i, m) { cnt += insertionSort(a, n, g[m - i - 1]); }

  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  rep(i, n) std::cin >> a[i];

  int cnt = shellSort(a, n);

  std::cout << cnt << '\n';

  rep(i, n) std::cout << a[i] << '\n';

  return 0;
}