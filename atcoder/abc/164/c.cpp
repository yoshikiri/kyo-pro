#include <iostream>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  std::cin >> n;
  std::set<std::string> all;

  all.clear();
  std::string s;
  rep(i, n) {
    std::cin >> s;
    all.insert(s);
  }

  std::cout << all.size() << '\n';
  return 0;
}
