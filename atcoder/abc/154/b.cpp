#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  rep(i, s.length()) { cout << 'x'; }
  cout << '\n';
  return 0;
}
