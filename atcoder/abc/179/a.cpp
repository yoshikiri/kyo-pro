#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  if (s[s.size() - 1] == 's')
    s += "es";
  else
    s += "s";
  cout << s << endl;
  return 0;
}
