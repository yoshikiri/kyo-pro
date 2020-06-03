#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll n;
  cin >> n;

  if (n % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0, d = 2;
  while (d <= n) {
    d *= 5;
    ans += n / d;
  }

  cout << ans << endl;

  return 0;
}
