#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ans += (ll)(a + b) * (b - a + 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
