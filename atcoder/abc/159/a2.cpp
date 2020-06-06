#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  int ans = n * (n - 1) / 2;
  ans += m * (m - 1) / 2;

  cout << ans << endl;
  return 0;
}
