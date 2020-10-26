#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  bool ans = true;
  for (int i = n - 1; i >= 1; --i) {
    if (h[i - 1] <= h[i]) continue;
    --h[i - 1];
    if (h[i - 1] > h[i]) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
