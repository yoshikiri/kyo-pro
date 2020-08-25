#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k;
  cin >> k;
  int x = 7;
  rep(i, k + 1) {
    if (x % k == 0) {
      cout << i + 1 << endl;
      return 0;
    }
    x = (x * 10 + 7) % k;
  }
  cout << -1 << endl;
  return 0;
}
