#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// ll gcd(ll a, ll b) {
//   if (b == 0) return a;
//   return gcd(b, a % b);
// }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;

  return 0;
}
