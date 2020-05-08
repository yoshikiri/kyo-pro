#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  std::string s;
  std::cin >> s;

  int n = s.length();

  int cnt[2019] = {0};
  cnt[0] = 1;
  int acc = 0, mult = 1;
  for (int i = n - 1; i >= 0; --i) {
    acc += (s[i] - '0') * mult;
    acc %= 2019;
    mult *= 10;
    mult %= 2019;
    cnt[acc]++;
  }

  int sum = 0;
  rep(i, 2019) { sum += cnt[i] * (cnt[i] - 1) / 2; }

  std::cout << sum << '\n';

  return 0;
}
