#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> to[n];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> g(n, -1);
  int cur = 0;
  rep(i, n) {
    if (g[i] != -1) continue;
    queue<int> q;
    q.push(i);
    g[i] = ++cur;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : to[u]) {
        if (g[v] != -1) continue;
        g[v] = g[u];
        q.push(v);
      }
    }
    ++cur;
  }

  map<int, int> mp;
  rep(i, n)++ mp[g[i]];
  int ans = 0;
  for (auto p : mp) ans = max(ans, p.second);
  cout << ans << endl;
  return 0;
}
