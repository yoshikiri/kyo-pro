#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  cin >> x;
  int s = 1000 - x;
  int ans = 0;
  int m[] = {500, 100, 50, 10, 5, 1};
  rep(i, 6) {
    ans += s / m[i];
    s %= m[i];
  }
  cout << ans << endl;
  return 0;
}
