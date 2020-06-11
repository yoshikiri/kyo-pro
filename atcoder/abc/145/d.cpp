#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll f(int x, int y) {
  if (x == 0 && y == 0) return 1;
  if (x < 0 && y < 0) return 0;
  return (f(x - 2, y - 1) % mod + f(x - 1, y - 2) % mod) % mod;
}

ll modpow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % mod;
    k = k * k % mod;
    n /= 2;
  }
  return res;
}

ll choose(ll n, ll k) {
  ll x = 1, y = 1;
  rep(i, k) {
    x = x * (n - i) % mod;
    y = y * (i + 1) % mod;
  }
  return x * modpow(y, mod - 2) % mod;
}

int main() {
  int x, y;
  cin >> x >> y;

  vector<P> move;
  rep(i, max(x, y)) {
    int a = i, b = y - 2 * a;
    if (a + 2 * b == x) {
      move.push_back({a, b});
    }
  }

  ll ans = 0;
  for (auto p : move) {
    ans = choose(p.first + p.second, p.first);
  }
  cout << ans << endl;

  return 0;
}
