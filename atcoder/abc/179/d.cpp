#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<P> ran(k);
  rep(i, k) cin >> ran[i].first >> ran[i].second;

  vector<ll> dp(n + 1);
  vector<ll> s(n + 2);
  dp[0] = 1;
  s[1] = 1;
  for (int i = 1; i <= n; ++i) {
    rep(j, k) {
      int li = i - ran[j].second;
      int ri = i - ran[j].first;
      if (ri < 0) continue;
      li = max(li, 0);
      (dp[i] += s[ri + 1] - s[li] + mod) %= mod;
    }
    s[i + 1] = (s[i] + dp[i]) % mod;
  }

  cout << dp[n - 1] % mod << endl;
  return 0;
}
