#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

ll pow(ll k, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k;
    k = k * k;
    n /= 2;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    double now = 1.0 / n;
    int m = 0;
    while (j < k) {
      j *= 2;
      ++m;
    }
    now *= 1.0 / pow(2, m);
    ans += now;
  }
  printf("%.15f\n", ans);
  return 0;
}
