#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  rep(i, n / 2) {
    if (s[i] != s[n - i - 1]) ++ans;
  }

  cout << ans << endl;
  return 0;
}
