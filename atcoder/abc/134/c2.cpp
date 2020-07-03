#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  vector<int> b(n);
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.rbegin(), b.rend());
  int mx1 = b[0], mx2 = b[1];
  rep(i, n) {
    if (a[i] == mx1)
      cout << mx2 << endl;
    else
      cout << mx1 << endl;
  }

  return 0;
}
