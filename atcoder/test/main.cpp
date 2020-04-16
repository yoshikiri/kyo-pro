#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{5, 1, 2};

  v.push_back(4);

  for (auto it = v.begin(); it != v.end(); it++) {
    std::cout << *it << '\n';
  }
  return 0;
}