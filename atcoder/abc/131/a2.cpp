#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  rep(i, s.size() - 1) {
    if (s[i] == s[i + 1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
  return 0;
}
