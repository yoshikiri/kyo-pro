#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k;
  cin >> k;

  vector<bool> isUsed(k);
  int x = 7 % k;
  isUsed[x] = true;
  rep(i, k) {
    if (x == 0) {
      cout << i + 1 << endl;
      return 0;
    }

    x = (x * 10 % k + 7) % k;
    if (isUsed[x]) {
      cout << -1 << endl;
      return 0;
    }
    isUsed[x] = true;
  }

  cout << -1 << endl;
  return 0;
}
