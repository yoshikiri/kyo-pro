#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int dp[100005];

int f(int i) {
  if (i < 0) return 0;
  if (dp[i] != -1) return dp[i];
  return dp[i] = (f(i - 1) + f(i - 2)) % mod;
}

int main() {
  int n, m;
  cin >> n >> m;

  rep(i, n + 1) dp[i] = -1;
  rep(i, m) {
    int x;
    cin >> x;
    dp[x] = 0;
  }
  dp[0] = 1;
  f(n);
  cout << dp[n] << endl;
  return 0;
}
