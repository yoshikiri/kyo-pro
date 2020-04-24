#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1);
  int m[n + 1][n + 1];
  for (int i = 1; i < n + 1; ++i) m[i][i] = 0;

  for (int i = 1; i < n + 1; ++i) { std::cin >> p[i - 1] >> p[i]; }

  // for (int l = 2; l < n + 1; ++l) {
  //   for (int i = 1; i <= n - l + 1; ++i) {
  //     int j = i + l - 1;
  //     m[i][j] = 1 << 21;
  //     for (int k = i; k < j; ++k) {
  //       m[i][j] =
  //           std::min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] *
  //           p[j]);
  //     }
  //   }
  // }

  for (int l = 2; l < n + 1; ++l) {
    for (int i = 1; i <= n - l + 1; ++i) {
      int j = i + l - 1;

      m[i][j] = 1 << 21;
      for (int k = i; k < j; ++k) {
        m[i][j] =
            std::min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
    }
  }
  std::cout << m[1][n] << '\n';
  return 0;
}
