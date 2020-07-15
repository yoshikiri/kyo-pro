#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int y;
  cin >> y;
  bool ok = false;
  if (y % 400 == 0)
    ok = true;
  else if (y % 100 == 0)
    ok = false;
  else if (y % 4 == 0)
    ok = true;
  else
    ok = false;
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
