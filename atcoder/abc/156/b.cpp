#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;

  int ans = log(n) / log(k) + 1;

  cout << ans << '\n';
  return 0;
}
