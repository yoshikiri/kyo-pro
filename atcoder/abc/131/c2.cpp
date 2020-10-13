#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll a, b;
  int c, d;
  cin >> a >> b >> c >> d;

  auto f = [&](ll x) { return x - x / c - x / d + x / lcm(c, d); };
  ll ans = f(b) - f(a - 1);
  cout << ans << endl;
  return 0;
}
