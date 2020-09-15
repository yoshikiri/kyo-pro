#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  string L = s.substr(0, 2);
  string R = s.substr(2, 2);
  int l = 10 * (L[0] - '0') + (L[1] - '0');
  int r = 10 * (R[0] - '0') + (R[1] - '0');
  if (1 <= l && l <= 12 && 1 <= r && r <= 12) {
    cout << "AMBIGUOUS" << endl;
    return 0;
  }
  if (1 <= l && l <= 12 && 0 <= r && r <= 99) {
    cout << "MMYY" << endl;
    return 0;
  }
  if (0 <= l && l <= 99 && 1 <= r && r <= 12) {
    cout << "YYMM" << endl;
    return 0;
  }
  cout << "NA" << endl;
  return 0;
}
