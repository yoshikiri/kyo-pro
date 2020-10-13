#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int mx = (n - 1) * (n - 2) / 2;
  if (k > mx) {
    cout << "-1" << endl;
    return 0;
  }

  int m = n - 1;
  int r = mx - k;
  cout << m + r << endl;
  rep(i, m) printf("%d %d\n", 1, i + 2);
  int cnt = 0;
  rep(i, n) {
    rep(j, i) {
      if (cnt == r) break;
      printf("%d %d\n", j + 2, i + 2);
      ++cnt;
    }
  }
  return 0;
}
