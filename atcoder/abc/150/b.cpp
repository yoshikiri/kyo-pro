#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  rep(i, n - 2) {
    if (s.substr(i, 3) == "ABC") ++ans;
    // if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ++ans;
  }

  cout << ans << endl;
  return 0;
}
