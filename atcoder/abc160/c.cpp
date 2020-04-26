// 23:53-00::06
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k, n;
  std::cin >> k >> n;
  std::vector<int> a(n);
  rep(i, n) std::cin >> a[i];
  a.push_back(a[0] + k);

  int max = 0;
  rep(i, n) { max = std::max(max, a[i + 1] - a[i]); }

  std::cout << k - max << '\n';
  return 0;
}
