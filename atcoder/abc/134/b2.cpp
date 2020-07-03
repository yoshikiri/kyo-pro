#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  int k = 2 * d + 1;
  int ans = (n + k - 1) / k;
  cout << ans << endl;
  return 0;
}
