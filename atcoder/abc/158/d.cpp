#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  std::string s;
  std::cin >> s;

  int q;
  std::cin >> q;

  std::string t;

  rep(qi, q) {
    int u;
    std::cin >> u;
    if (u == 1) {
      swap(s, t);
    } else {
      int f;
      char c;
      std::cin >> f >> c;
      if (f == 1) {
        t += c;
      } else {
        s += c;
      }
    }
  }

  reverse(t.begin(), t.end());
  t += s;

  std::cout << t << '\n';
  return 0;
}
