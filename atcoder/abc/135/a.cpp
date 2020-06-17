#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    puts("0");
    return 0;
  }

  int k = (a + b) / 2;
  if (abs(a - k) == abs(b - k))
    cout << k << endl;
  else
    puts("IMPOSSIBLE");

  return 0;
}
