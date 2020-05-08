// 23:45-
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  std::string s;
  std::cin >> s;
  if (s[2] == s[3] && s[4] == s[5])
    std::cout << "Yes" << '\n';
  else
    std::cout << "No" << '\n';
  return 0;
}
