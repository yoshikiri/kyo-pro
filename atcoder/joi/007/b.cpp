#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int x = 0, y = 0;
  rep(i, n - 2) {
    if (s.substr(i, 3) == "JOI")
      ++x;
    else if (s.substr(i, 3) == "IOI")
      ++y;
  }
  cout << x << endl;
  cout << y << endl;
  return 0;
}
