#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int mod = 1e9 + 7;

ll dp[100005];

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ng(n);
  rep(i, m) {
    int a;
    cin >> a;
    ng[a] = 1;
  }

  vector<ll> dp(n + 2);
  dp[0] = 1;
  rep(i, n) {
    if (ng[i]) continue;
    // if (dp[i] == -1) continue;
    dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
    dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
  }
  cout << dp[n] << endl;
  return 0;
}
