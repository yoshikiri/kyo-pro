#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  // double ans = 0;
  // for (int i = 1; i <= n; ++i) {
  //   if (i >= k) {
  //     ans += (double)(n - i + 1) / n;
  //     break;
  //   }
  //   int r = log2(k / i) + 1;
  //   ans += 1.0 / (n * pow(2, r));
  // }

  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    int now = i;
    double tmp = 1.0;
    while (now < k) {
      now *= 2;
      tmp /= 2.0;
    }
    ans += tmp;
  }

  printf("%.12f\n", ans / n);
  return 0;
}
