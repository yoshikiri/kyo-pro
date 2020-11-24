#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int k, x;
  cin >> k >> x;
  int l = x - k + 1;
  int r = x + k - 1;
  for (int i = l; i <= r; ++i) printf("%d%c", i, (i == r ? '\n' : ' '));
  return 0;
}
