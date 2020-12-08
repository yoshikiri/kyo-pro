#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << 0 << endl;
    return 0;
  }

  int sum = 1;
  int ans = 0;
  while (sum < b) {
    sum += a - 1;
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
