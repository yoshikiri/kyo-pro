#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const ll INF = 1e15;

int main() {
  int n;
  cin >> n;
  vector<P> to[n];
  rep(i, n - 1) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    to[a].push_back({b, w});
    to[b].push_back({a, w});
  }

  vector<int> g(n, -1);
  vector<ll> d(n, INF);
  queue<int> q;
  g[0] = 0;
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto p : to[u]) {
      if (d[p.first] != INF) continue;
      d[p.first] = d[u] + p.second;
      g[p.first] = ((p.second % 2 == 0) ? g[u] : (1 - g[u]));
      q.push(p.first);
    }
  }

  rep(i, n) cout << g[i] << endl;
  return 0;
}
