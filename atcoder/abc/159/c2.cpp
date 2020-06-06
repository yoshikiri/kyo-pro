#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int l;
  cin >> l;
  double ans = (l / 3.0) * (l / 3.0) * (l / 3.0);
  printf("%.15f\n", ans);
  return 0;
}
