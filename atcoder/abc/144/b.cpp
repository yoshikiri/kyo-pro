#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;

  if (n > 81) {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 9; i >= 1; --i) {
    if (n % i == 0) {
      n /= i;
      break;
    }
  }
  if (n <= 9)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
