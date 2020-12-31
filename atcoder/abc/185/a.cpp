#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a[4];
  rep(i, 4) cin >> a[i];
  int mn = 100;
  rep(i, 4) mn = min(mn, a[i]);
  cout << mn << endl;
  return 0;
}
