#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int ans = n;
  int cur = 1;
  rep(i, n) {
    if (a[i] == cur) {
      --ans;
      ++cur;
    }
  }

  if (ans == n) ans = -1;
  cout << ans << endl;
  return 0;
}
