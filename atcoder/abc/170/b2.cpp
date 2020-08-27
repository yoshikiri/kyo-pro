#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y;
  cin >> x >> y;
  rep(i, x + 1) {
    int r = y - 2 * i;
    if (4 * (x - i) == r) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
