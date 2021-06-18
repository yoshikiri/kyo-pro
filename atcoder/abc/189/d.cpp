#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll npow(ll n, int k) {
  ll res = 1;
  while (k > 0) {
    if (k & 1) res *= n;
    n *= n;
    k /= 2;
  }
  return res;
}

bool s[65];

ll f(int i) {
  if (i == 1) {
    if (s[i - 1]) return 1LL;
    return 3LL;
  }
  if (s[i - 1]) return f(i - 1);
  return npow(2, i) + f(i - 1);
}

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    string x;
    cin >> x;
    s[i] = (x == "AND");
  }
  ll ans = f(n);
  cout << ans << endl;
  return 0;
}
