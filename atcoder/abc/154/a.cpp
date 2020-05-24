#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t, u;
  cin >> s >> t;
  int a, b;
  cin >> a >> b >> u;

  if (u == s)
    --a;
  else
    --b;

  cout << a << ' ' << b;

  return 0;
}
