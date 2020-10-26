#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    string x = to_string(i);
    if ((int)x.size() % 2 == 1) ++ans;
  }
  cout << ans << endl;
  return 0;
}
