#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int a, b;
  cin >> a >> b;
  --a, --b;
  int c[3] = {1, 1, 1};
  c[a] = c[b] = 0;
  rep(i, 3) if (c[i]) cout << i + 1 << endl;
  return 0;
}
