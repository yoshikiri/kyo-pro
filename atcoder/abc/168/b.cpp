#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k;
  string s;
  cin >> k >> s;

  if (s.length() <= k)
    cout << s << '\n';
  else {
    s = s.substr(0, k);
    s += "...";
    cout << s << '\n';
  }
  return 0;
}
