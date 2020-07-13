#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    if (a[i] & 1) ++ans;
  }
  cout << ans << endl;
  return 0;
}
