#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  bool x = s[0] == s[1] && s[1] == s[2];
  cout << (x ? "Won" : "Lost") << endl;
  return 0;
}
