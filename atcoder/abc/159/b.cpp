#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

bool isPalindrome(std::string s) {
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[n - i - 1]) return false;
  }

  return true;
}

int main() {
  std::string S;
  std::cin >> S;

  int n = S.length();
  if (isPalindrome(S) && isPalindrome(S.substr(0, n / 2)) &&
      isPalindrome(S.substr(n / 2 + 1))) {
    std::cout << "Yes" << '\n';
  } else {
    std::cout << "No" << '\n';
  }
  return 0;
}
