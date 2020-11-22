#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;
  int ans = max(0, (2 * a + 100) - b);
  cout << ans << endl;
  return 0;
}
