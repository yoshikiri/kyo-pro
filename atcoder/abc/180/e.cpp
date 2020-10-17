#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct P {
  int x;
  int y;
  int z;
};

const int INF = 1001001001;

// p1 -> p2
int cost(P p1, P p2) {
  return abs(p1.x - p2.x) + abs(p1.y - p2.y) + max(0, p2.z - p1.z);
}

int main() {
  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, n) cin >> v[i].x >> v[i].y >> v[i].z;

  vector<vector<int>> dp(1 << n, vector<int>(n, INF));
  // initial state: only 0th vertext is visited
  dp[1][0] = 0;

  for (int s = 1; s < (1 << n); ++s) {
    rep(i, n) {
      if (!(s >> i & 1)) continue;   // i is not visited
      if (dp[s][i] == INF) continue; // impossible state
      rep(j, n) {
        if (s >> j & 1) continue;
        dp[s | 1 << j][j] = min(dp[s | 1 << j][j], dp[s][i] + cost(v[i], v[j]));
      }
    }
  }

  int ans = INF;
  for (int i = 1; i < n; ++i) {
    ans = min(ans, dp[(1 << n) - 1][i] + cost(v[i], v[0]));
  }
  cout << ans << endl;
  return 0;
}
