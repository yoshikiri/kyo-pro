#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> to[n];
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    to[u].push_back(v);
  }
  int s, t;
  cin >> s >> t;
  --s, --t;

  const int INF = 1001001001;
  vector<vector<int>> dist(n, vector<int>(3, INF));
  dist[s][0] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : to[u]) {
      rep(i, 3) {
        int du = dist[u][i];
        if (du == INF) continue;
        int m = (du + 1) % 3;
        if (dist[v][m] != INF) continue;
        dist[v][m] = du + 1;
        q.push(v);
      }
    }
  }

  int ans = dist[t][0];
  cout << (ans == INF ? -1 : ans / 3) << endl;
  return 0;
}
