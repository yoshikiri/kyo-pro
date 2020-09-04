#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  cout << ((double)d / s <= t ? "Yes" : "No") << endl;
  return 0;
}
