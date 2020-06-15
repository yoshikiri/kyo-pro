#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;

  if (b == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (a >= b) {
    cout << 1 << endl;
    return 0;
  }

  int ans = (b - a + (a - 2)) / (a - 1) + 1;
  cout << ans << endl;
  return 0;
}
