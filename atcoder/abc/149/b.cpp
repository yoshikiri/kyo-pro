#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  ll a, b, k;
  cin >> a >> b >> k;

  ll ra = a - min(a, k);
  ll rb = max(0LL, b - (k - min(a, k)));

  // ll x = min(a, k);
  // a -= x;
  // k -= x;
  // b -= min(b, k);

  cout << ra << " " << rb << endl;
  return 0;
}
