#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  reverse(h, h + n);
  rep(i, n - 1) {
    if (h[i + 1] > h[i]) --h[i + 1];
  }

  bool ans = true;
  rep(i, n - 1) {
    if (h[i] < h[i + 1]) ans = false;
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
