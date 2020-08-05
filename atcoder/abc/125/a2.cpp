#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, t;
  cin >> a >> b >> t;
  int ans = t / a * b;
  cout << ans << endl;
  return 0;
}
