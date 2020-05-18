#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
// using P = pair<int, int>;

const int MAX = 15;
const int INF = 1 << 21;
int dp[1 << MAX][MAX];
int dist[MAX][MAX];

int dfs(int s, int v, int n) {
  if (dp[s][v] >= 0) { return dp[s][v]; }

  if (s == (1 << n) - 1 && v == 0) { return dp[s][v] = 0; }

  int ans = INF;
  rep(u, n) {
    if (!(s >> u & 1)) { ans = min(ans, dfs(s | 1 << u, u, n) + dist[v][u]); }
  }

  dp[s][v] = ans;
  return ans;
}

int main() {
  int v, e;
  cin >> v >> e;

  vector<pair<int, int>> to[v];

  rep(i, e) {
    int s, t, d;
    cin >> s >> t >> d;
    to[s].push_back(make_pair(t, d));
  }

  rep(i, 1 << v) rep(j, v) dp[i][j] = INF;
  dp[1][0] = 0;
  // rep(i, v) rep(j, v) dist[i][j] = INF;
  // dist[0][0] = 0;

  for (int s = 0; s < (1 << v); ++s) {
    for (int i = 0; i < v; ++i) {
      if (dp[s][i] == INF) continue;
      // cout << s << '\n';

      for (auto u : to[i]) {
        // printf("i, u = %d, %d\n", i, u.first);
        if ((s >> u.first) & 1) continue;
        int nexts = s | (1 << u.first);
        int nextd = dp[s][i] + u.second;
        // printf("nexts=%d, dp[s][i]=%d, u.second=%d\n", nexts, dp[s][i],
        //        u.second);

        dp[nexts][u.first] = min(dp[nexts][u.first], nextd);
      }
    }
  }

  int all = (1 << v) - 1;
  int ans = INF;
  rep(i, v) {
    if (dp[all][i] == INF) continue;
    int d = INF;
    for (auto u : to[i])
      if (u.first == 0) d = u.second;
    int temp = dp[all][i] + d;
    ans = min(ans, temp);
  }

  // int ans = dfs(0, 0, v);
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}