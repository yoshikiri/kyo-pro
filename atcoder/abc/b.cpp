// 16:25 - 16:32
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, l;
  std::cin >> n >> l;

  int a[n];
  rep(i, n) { a[i] = l + i; }

  int m = 1 << 21;
  rep(i, n) { m = (abs(m) < abs(a[i])) ? m : a[i]; }

  int ans = 0;
  rep(i, n) { ans += a[i]; }
  ans -= m;
  std::cout << ans << '\n';
  return 0;
}
