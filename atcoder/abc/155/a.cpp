#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  bool ans = false;
  if (a == b && b != c) ans = true;
  if (a == c && a != b) ans = true;
  if (b == c && a != c) ans = true;

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
