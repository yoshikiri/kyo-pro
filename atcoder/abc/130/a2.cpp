#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, a;
  cin >> x >> a;
  int ans = 0;
  if (x < a)
    ans = 0;
  else
    ans = 10;
  cout << ans << endl;
  return 0;
}
