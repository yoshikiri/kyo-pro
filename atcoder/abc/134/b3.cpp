#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, d;
  cin >> n >> d;
  d = 2 * d + 1;
  cout << (n + d - 1) / d << endl;
  return 0;
}
