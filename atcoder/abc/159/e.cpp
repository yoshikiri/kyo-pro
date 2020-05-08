#include <bitset>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  rep(div, 1 << 8) {
    std::cout << std::bitset<8>(div) << '\n';
    std::cout << ((div >> 3 & 1) ? "true" : "false") << '\n';
  }
  return 0;
}
