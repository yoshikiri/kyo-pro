#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll Pow(ll k, ll n) {
  ll res = 1;
  rep(i, n) res *= k;
  return res;
}

int main() {
  ll n;
  cin >> n;
  int a = 0, b = 0;
  ll x = 1;
  while (x < n) {
    x *= 3;
    ++a;
  }
  x = 1;
  while (x < n) {
    x *= 5;
    ++b;
  }

  for (int i = 1; i < a; ++i) {
    for (int j = 1; j < b; ++j) {
      ll p = Pow(3, i), q = Pow(5, j);
      if (p + q == n) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
