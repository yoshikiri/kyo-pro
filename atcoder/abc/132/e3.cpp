#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;

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

  queue<int> q;
  q.push(s);
  vector<vector<int>> d(n, vector<int>());
  d[s].push_back(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto du : d[u]) {
      for (auto v : to[u]) {
        bool ok = true;
        for (auto r : d[v]) {
          if (((du + 1) % 3) == (r % 3)) ok = false;
        }
        if (!ok) continue;
        d[v].push_back(du + 1);
        q.push(v);
      }
    }
  }

  int ans = INF;
  for (auto r : d[t]) {
    if (r % 3 == 0) {
      ans = min(ans, r / 3);
    }
  }
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
