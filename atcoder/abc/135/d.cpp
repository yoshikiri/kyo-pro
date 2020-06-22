#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  const int N = 13;
  vector<ll> dp(N);
  dp[0] = 1;
  ll mul = 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    vector<ll> nextDp(N);
    char c = s[i];
    if (c == '?') {
      rep(k, 10) {
        rep(j, N) {
          nextDp[(k * mul + j) % N] += dp[j];
          nextDp[(k * mul + j) % N] %= mod;
        }
      }
    } else {
      int k = s[i] - '0';
      rep(j, N) {
        nextDp[(k * mul + j) % N] += dp[j];
        nextDp[(k * mul + j) % N] %= mod;
      }
    }

    mul *= 10;
    mul %= N;
    rep(j, N) dp[j] = nextDp[j];
  }

  cout << dp[5] << endl;
  return 0;
}
