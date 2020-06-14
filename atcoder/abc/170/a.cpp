#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int ans;
  rep(i, 5) {
    int x;
    cin >> x;
    if (x == 0) ans = i;
  }

  cout << ans + 1 << endl;
  return 0;
}
