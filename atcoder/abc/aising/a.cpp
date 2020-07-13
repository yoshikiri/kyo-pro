#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l, r, d;
  cin >> l >> r >> d;

  auto f = [&](int k) { return k / d; };

  cout << f(r) - f(l - 1) << endl;
  return 0;
}
