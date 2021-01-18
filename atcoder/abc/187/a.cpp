#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string a, b;
  cin >> a >> b;
  int s1 = (a[0] - '0') + (a[1] - '0') + (a[2] - '0');
  int s2 = (b[0] - '0') + (b[1] - '0') + (b[2] - '0');
  cout << max(s1, s2) << endl;
  return 0;
}
