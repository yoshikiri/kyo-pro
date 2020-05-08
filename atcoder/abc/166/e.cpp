#include <iostream>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  long long a[n];
  rep(i, n) std::cin >> a[i];

  std::map<long long, int> d1;

  rep(i, n) { d1[i + a[i]]++; }

  long long ans = 0;
  rep(j, n) { ans += d1[j - a[j]]; }

  std::cout << ans << '\n';

  return 0;
}
