#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll a;
  string b;
  cin >> a >> b;

  ll c = 0;
  rep(i, 4) {
    if (i == 1) continue;
    int x = b[i] - '0';
    if (i == 0) x *= 100;
    if (i == 2) x *= 10;
    if (i == 3) x *= 1;
    c += x;
  }

  ll ans = a * c / 100;
  cout << ans << endl;
  return 0;
}
