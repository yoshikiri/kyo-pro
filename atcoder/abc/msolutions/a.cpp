#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  cin >> x;
  int ans = 0;
  if (x <= 599)
    ans = 8;
  else if (x <= 799)
    ans = 7;
  else if (x <= 999)
    ans = 6;
  else if (x <= 1199)
    ans = 5;
  else if (x <= 1399)
    ans = 4;
  else if (x <= 1599)
    ans = 3;
  else if (x <= 1799)
    ans = 2;
  else if (x <= 1999)
    ans = 1;

  cout << ans << endl;
  return 0;
}
