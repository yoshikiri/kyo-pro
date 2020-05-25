#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll h;
  cin >> h;

  int k = log(h) / log(2);
  ll ans = pow(2, k + 1) - 1;

  cout << ans << endl;
  return 0;
}
