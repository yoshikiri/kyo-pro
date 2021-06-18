#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, x;
  cin >> n >> x;
  x *= 100;
  int v[n], p[n];
  rep(i, n) cin >> v[i] >> p[i];

  int sum = 0;
  rep(i, n) {
    sum += v[i] * p[i];
    if (sum > x) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
