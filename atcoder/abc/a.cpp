// 16:22 - 16::25
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  std::string s;
  std::cin >> s;

  bool isGood = true;
  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == s[i + 1]) isGood = false;
  }

  std::cout << (isGood ? "Good" : "Bad") << '\n';
  return 0;
}
