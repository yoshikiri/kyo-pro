#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << 0 << endl;
    return 0;
  }
  if ((a + b) % 2 != 0) {
    puts("IMPOSSIBLE");
    return 0;
  }
  cout << (a + b) / 2 << endl;
  return 0;
}
