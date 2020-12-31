#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l;
  cin >> l;
  ll ans = 1;
  rep(i, 11) {
    ans *= l - 1 - i;
    ans /= i + 1;
  }
  cout << ans << endl;
  return 0;
}
