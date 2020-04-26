#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int s, w;
  std::cin >> s >> w;

  if (s <= w)
    std::cout << "unsafe" << '\n';
  else
    std::cout << "safe" << '\n';
  return 0;
}
