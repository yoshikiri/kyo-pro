#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (c == 0) {
    cout << (a > b ? "Takahashi" : "Aoki") << endl;
  } else {
    cout << (a < b ? "Aoki" : "Takahashi") << endl;
  }
  return 0;
}
