#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int ans;
  if (a >= k)
    ans = k;
  else {
    if (b >= k - a)
      ans = a;
    else
      ans = a - (k - (a + b));
  }

  cout << ans << endl;
  return 0;
}
