#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y;
  cin >> x >> y;

  for (int i = 0; i <= x; ++i) {
    int j = x - i;
    if (2 * i + 4 * j == y) {
      puts("Yes");
      return 0;
    }
  }

  puts("No");
  return 0;
}
