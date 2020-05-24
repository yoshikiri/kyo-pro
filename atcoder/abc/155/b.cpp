#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  bool ans = true;

  rep(i, n) {
    int a;
    cin >> a;
    if (a % 2 == 0) {
      if (a % 3 != 0 && a % 5 != 0) ans = false;
    }
  }

  cout << (ans ? "APPROVED" : "DENIED") << endl;

  return 0;
}
