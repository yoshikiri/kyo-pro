#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  int s[m], c[m];
  rep(i, m) cin >> s[i] >> c[i];

  rep(i, 1000) {
    string str = to_string(i);

    bool now = true;
    rep(j, m) {
      int p = s[j] - 1, q = c[j];
      if (str[p] != q + '0') {
        now = false;
        continue;
      }
    }

    if (str.size() != n) continue;

    if (now) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
