#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  rep(i, s.length()) {
    if (s[i] != t[i]) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
