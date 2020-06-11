#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = n;
  rep(i, n - 1) {
    if (s[i + 1] == s[i]) {
      --ans;
    }
  }

  cout << ans << endl;
  return 0;
}
