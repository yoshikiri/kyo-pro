#include <iostream>
#include <stdio.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    std::cout << n << '\n';
  }

  return 0;
}