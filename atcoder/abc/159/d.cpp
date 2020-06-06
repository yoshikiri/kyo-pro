#include <iostream>
#include <map>

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  int a[n];
  rep(i, n) std::cin >> a[i];

  std::map<int, ll> mp;
  rep(i, n) { mp[a[i]]++; }

  ll sum = 0;
  for (auto p : mp) sum += p.second * (p.second - 1) / 2;

  rep(k, n) { std::cout << sum - (mp[a[k]] - 1) << '\n'; }
  return 0;
}
