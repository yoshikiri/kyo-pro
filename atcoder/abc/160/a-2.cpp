#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  if (s[2] == s[3] && s[4] == s[5])
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}
