#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string n;
  cin >> n;

  bool ans = false;
  rep(i, n.length()) {
    if (n[i] == '7') ans = true;
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
