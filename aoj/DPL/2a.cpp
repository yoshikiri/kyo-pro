#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> to[n];
  rep(i, m) {
    int s, t, d;
    cin >> s >> t >> d;
    to[s].push_back({t, d});
  }

  vector<vector<int>> dp(1 << n, vector<int>(n, INF));
  dp[0][0] = 0;
  rep(s, 1 << n) {
    rep(i, n) {
      for (auto p : to[i]) {
        int j = p.first;
        if (!(s >> j & 1))
          dp[s | 1 << j][j] = min(dp[s | 1 << j][j], dp[s][i] + p.second);
      }
    }
  }

  int ans = dp[(1 << n) - 1][0];
  if (ans == INF)
    ans = -1;
  cout << ans << endl;

  return 0;
}