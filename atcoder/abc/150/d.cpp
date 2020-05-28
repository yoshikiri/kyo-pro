#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int f(int x) {
  int res = 0;
  while (x % 2 == 0) {
    ++res;
    x /= 2;
  }

  return res;
}

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (a[i] % 2 == 1) {
      cout << 0 << endl;
      return 0;
    }
    a[i] /= 2;
  }

  int t = f(a[0]);
  rep(i, n) {
    if (f(a[i]) != t) {
      cout << 0 << endl;
      return 0;
    }
    a[i] >>= t;
  }

  m >>= t;

  ll l = 1;
  rep(i, n) {
    l = lcm(l, a[i]);
    if (l > m) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans = m / l;
  ans = (ans + 1) / 2;

  cout << ans << endl;
  return 0;
}
