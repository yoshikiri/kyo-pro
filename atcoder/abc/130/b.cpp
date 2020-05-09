#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, x;
  cin >> n >> x;

  int L[n];
  rep(i, n) cin >> L[i];
  int D[n];

  D[0] = 0;
  for (int i = 1; i < n + 1; ++i) { D[i] = D[i - 1] + L[i - 1]; }

  int ans = 0;
  rep(i, n + 1) {
    if (D[i] <= x) { ++ans; }
  }

  cout << ans << endl;
  return 0;
}
