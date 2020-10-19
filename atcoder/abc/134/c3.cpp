#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.rbegin(), b.rend());
  int mx = b[0];
  int mx2 = b[1];
  rep(i, n) {
    if (a[i] == mx) {
      cout << (mx == mx2 ? mx : mx2) << endl;
    } else {
      cout << mx << endl;
    }
  }
  return 0;
}
