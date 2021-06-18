#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, s, d;
  cin >> n >> s >> d;
  int x[n], y[n];
  rep(i, n) cin >> x[i] >> y[i];

  bool ans = false;
  rep(i, n) {
    if (x[i] < s && y[i] > d) ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
