#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a[3][3];
  rep(i, 3) rep(j, 3) cin >> a[i][j];

  int n;
  cin >> n;
  bool d[3][3];
  rep(i, 3) rep(j, 3) d[i][j] = false;

  rep(i, n) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) if (a[i][j] == b) d[i][j] = true;
  }

  rep(i, 3) {
    if (d[i][0] && d[i][1] && d[i][2]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  rep(i, 3) {
    if (d[0][i] && d[1][i] && d[2][i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (d[0][0] && d[1][1] && d[2][2]) {
    cout << "Yes" << endl;
    return 0;
  }

  if (d[0][2] && d[1][1] && d[2][0]) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;

  return 0;
}
