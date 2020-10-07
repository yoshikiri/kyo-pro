#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll dp0[2005][2005];
ll dp1[2005][2005];

int main() {
  int n, m;
  cin >> n >> m;
  int s[n + 1], t[m + 1];
  rep(i, n) cin >> s[i];
  rep(i, m) cin >> t[i];

  dp0[0][0] = 1;
  rep(i, n + 1) rep(j, m + 1) {
    (dp0[i + 1][j] += dp0[i][j]) %= mod;
    (dp1[i][j] += dp0[i][j]) %= mod;
    (dp1[i][j + 1] += dp1[i][j]) %= mod;
    if (s[i] == t[j]) {
      (dp0[i + 1][j + 1] += dp1[i][j]) %= mod;
    }
  }
  cout << dp1[n][m] << endl;
  return 0;
}
