#include <iostream>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  std::cin >> n >> k;

  int *a = new int[n + 1];
  rep(i, n + 1) a[i] = i;

  long long sum = 0;

  for (long long i = k; i <= n + 1; ++i) {
    long long min = i * (i - 1) / 2;
    long long max = i * (2 * n - i + 1) / 2;

    long long m = max - min + 1;

    sum += m;
  }

  std::cout << sum % (1000000000 + 7) << '\n';

  return 0;
}
