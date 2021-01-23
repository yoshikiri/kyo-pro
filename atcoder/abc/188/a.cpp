#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, y;
  cin >> x >> y;
  bool ans = abs(x - y) < 3;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
