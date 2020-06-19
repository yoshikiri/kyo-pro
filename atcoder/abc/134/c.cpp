#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b, b + n);
  int mx = b[n - 1], mx2 = b[n - 2];

  rep(i, n) {
    if (a[i] == mx)
      cout << mx2 << endl;
    else
      cout << mx << endl;
  }
  return 0;
}
