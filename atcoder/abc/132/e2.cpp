#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;
int dist[100005][3];

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
  int sv, tv;
  cin >> sv >> tv;
  --sv, --tv;

  rep(i, n) rep(j, 3) dist[i][j] = INF;

  queue<P> q;
  q.push({sv, 0});
  dist[sv][0] = 0;
  while (!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();

    for (auto u : to[v]) {
      int nl = (l + 1) % 3;
      if (dist[u][nl] != INF) continue;
      dist[u][nl] = dist[v][l] + 1;
      q.push({u, nl});
    }
  }

  int ans = dist[tv][0];
  cout << (ans == INF ? -1 : ans / 3) << endl;
  return 0;
}
