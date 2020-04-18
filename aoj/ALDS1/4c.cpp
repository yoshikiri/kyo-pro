// 00:49 - 01:35

#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int convert(std::string str) {
  int len = str.length();

  int index = -1;
  int mult = 1;
  rep(i, len) {
    char c = str[i];
    if (c == 'A')
      index += 1 * mult;
    else if (c == 'C')
      index += 2 * mult;
    else if (c == 'G')
      index += 3 * mult;
    else if (c == 'T')
      index += 4 * mult;

    mult *= 4;
  }

  return index;
}

int main() {
  int n;
  std::cin >> n;

  bool *dict = new bool[16777216];
  for (int i = 0; i < 16777216; i++) {
    dict[i] = 0;
  }

  std::string com;
  std::string str;

  rep(i, n) {
    std::cin >> com >> str;
    int index = convert(str);
    if (com == "insert") {
      dict[index] = 1;
    } else {
      bool isIncluded = dict[index];
      if (isIncluded)
        std::cout << "yes" << '\n';
      else
        std::cout << "no" << '\n';
    }
  }

  return 0;
}
