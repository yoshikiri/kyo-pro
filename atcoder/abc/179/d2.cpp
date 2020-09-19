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
  ll cur = 0;
  dp[0] = 1;
  rep(i, n) {
    rep(j, k) {
      int li = i + ran[j].first;
      int ri = i + ran[j].second;
      if (li > n) continue;
      (s[li] += dp[i]) %= mod;
      if (ri < n) (s[ri + 1] -= dp[i] + mod) %= mod;
    }
    (cur += s[i + 1] + mod) %= mod;
    dp[i + 1] = (dp[i + 1] + cur) % mod;
  }
  cout << dp[n - 1] << endl;
  return 0;
}
