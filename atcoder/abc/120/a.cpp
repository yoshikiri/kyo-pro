#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = min(b / a, c);

  cout << ans << '\n';
  return 0;
}
