#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  int ans = x;
  rep(i, n) {
    if (s[i] == 'o')
      ++ans;
    else
      ans = max(0, ans - 1);
  }
  cout << ans << endl;
  return 0;
}
