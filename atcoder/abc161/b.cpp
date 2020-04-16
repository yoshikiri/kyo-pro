#include <algorithm>
#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int a[n];
  double sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  std::sort(a, a + n, std::greater<int>());

  if (a[m - 1] < sum / (4 * m)) {
    std::cout << "No" << '\n';
  } else {
    std::cout << "Yes" << '\n';
  }
  return 0;
}
