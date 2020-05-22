#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, r;
  cin >> n >> r;

  if (n >= 10)
    cout << r << '\n';
  else
    cout << r + 100 * (10 - n) << '\n';
  return 0;
}
