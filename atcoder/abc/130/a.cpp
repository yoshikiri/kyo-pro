#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, a;
  cin >> x >> a;

  cout << ((x < a) ? 0 : 10) << endl;
  return 0;
}
