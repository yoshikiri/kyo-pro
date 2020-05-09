#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k, x;
  cin >> k >> x;

  for (int i = x - k + 1; i < x + k; ++i) {
    if (i != x - k + 1) cout << " ";
    cout << i;
  }
  cout << endl;

  return 0;
}
