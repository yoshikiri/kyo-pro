#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct Edge {
  int to, id;
};

int main() {
  int n;
  cin >> n;
  vector<Edge> g[n];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back((Edge){b, i});
    g[b].push_back((Edge){a, i});
  }

  int mx = 0;
  rep(i, n) mx = max(mx, (int)g[i].size());

  int ans[n - 1];
  queue<int> q;
  vector<int> used(n);
  q.push(0);
  used[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int c = -1;
    for (auto x : g[u]) {
      int v = x.to, ei = x.id;
      if (used[v]) c = ans[ei];
    }

    int k = 1;
    for (auto x : g[u]) {
      int v = x.to, ei = x.id;
      if (used[v]) continue;
      if (k == c) ++k;
      ans[ei] = k;
      ++k;
      q.push(v);
      used[v] = 1;
    }
  }

  cout << mx << endl;
  rep(i, n - 1) cout << ans[i] << endl;

  return 0;
}
