#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int r = r2 - r1;
  int c = c2 - c1;

  int ans = 3;
  if (r == 0 && c == 0)
    ans = 0;
  else if (abs(r) == abs(c) || abs(r) + abs(c) <= 3)
    ans = 1;
  else if ((r1 + c1 + r2 + c2) % 2 == 0 || abs(r + c) <= 3 || abs(r - c) <= 3 ||
           abs(r) + abs(c) <= 6)
    ans = 2;
  cout << ans << endl;

  return 0;
}
