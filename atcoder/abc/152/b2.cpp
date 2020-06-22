#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;
  string ans;
  rep(i, max(a, b)) ans += '0' + min(a, b);
  cout << ans << endl;
  return 0;
}
