#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MAX_SIZE = 1 << 24;
int dict[MAX_SIZE];

int convert(std::string str) {
  int l = str.length();
  int sum = -1;
  int mult = 1;
  rep(i, l) {
    char c = str[l - 1 - i];
    if (c == 'A') {
      sum += mult;
    } else if (c == 'C') {
      sum += 2 * mult;
    } else if (c == 'G') {
      sum += 3 * mult;
    } else {
      sum += 4 * mult;
    }

    mult *= 4;
  }

  return sum;
}

void insert(std::string str) {
  int idx = convert(str);
  // std::cout << str << ", " << idx << '\n';
  dict[idx] = 1;
}

void find(std::string str) {
  int idx = convert(str);
  if (dict[idx] == 1)
    std::cout << "yes" << '\n';
  else
    std::cout << "no" << '\n';
}

int main() {
  int n;
  std::cin >> n;
  std::string com, str;

  rep(i, n) {
    std::cin >> com >> str;
    if (com == "insert") {
      insert(str);
    } else {
      find(str);
    }
  }
  return 0;
}