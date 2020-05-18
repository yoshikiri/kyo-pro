#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x;
  cin >> x;
  int c500 = x / 500;
  int c5 = (x - c500 * 500) / 5;

  cout << c500 * 1000 + c5 * 5 << '\n';
  return 0;
}
