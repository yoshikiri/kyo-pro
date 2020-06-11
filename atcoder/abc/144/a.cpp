#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;

  if (a <= 9 && b <= 9)
    cout << a * b << endl;
  else
    cout << -1 << endl;
  return 0;
}
