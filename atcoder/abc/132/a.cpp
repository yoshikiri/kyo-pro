#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  bool ans = true;
  if (s[0] != s[1]) ans = false;
  if (s[1] == s[2]) ans = false;
  if (s[2] != s[3]) ans = false;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
