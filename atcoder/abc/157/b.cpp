#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a[3][3];
  rep(i, 3) rep(j, 3) cin >> a[i][j];

  int n;
  cin >> n;
  rep(i, n) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) {
      if (a[i][j] == b) a[i][j] = -1;
    }
  }

  bool ans = false;
  if (a[0][0] + a[0][1] + a[0][2] == -3) ans = true;
  if (a[1][0] + a[1][1] + a[1][2] == -3) ans = true;
  if (a[2][0] + a[2][1] + a[2][2] == -3) ans = true;

  if (a[0][0] + a[1][0] + a[2][0] == -3) ans = true;
  if (a[0][1] + a[1][1] + a[2][1] == -3) ans = true;
  if (a[0][2] + a[1][2] + a[2][2] == -3) ans = true;

  if (a[0][0] + a[1][1] + a[2][2] == -3) ans = true;
  if (a[0][2] + a[1][1] + a[2][0] == -3) ans = true;

  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
