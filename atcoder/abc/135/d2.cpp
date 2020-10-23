#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

ll modpow(ll k, ll n, int m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % m;
    n /= 2;
    k = k * k % m;
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());

  vector<vector<int>> dp(n + 1, vector<int>(13));
  dp[0][0] = 1;
  rep(i, n) {
    rep(j, 13) {
      if (s[i] == '?') {
        rep(k, 10) {
          ll x = k * modpow(10, i, 13) % 13;
          int nj = (j + x) % 13;
          (dp[i + 1][nj] += dp[i][j]) %= mod;
        }
      } else {
        ll x = (s[i] - '0') * modpow(10, i, 13) % 13;
        int nj = (j + x) % 13;
        (dp[i + 1][nj] += dp[i][j]) %= mod;
      }
    }
  }

  cout << dp[n][5] << endl;
  return 0;
}
