#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  bool ok = true;
  int n = s.size();
  rep(i, n) {
    if (s[i] == 'U' || s[i] == 'D') continue;
    if (i & 1) {
      if (s[i] == 'R') ok = false;
    } else {
      if (s[i] == 'L') ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
