#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

vector<int> calcDist(int s, int n, vector<int> *to) {
  const int INF = 1001001001;
  vector<int> d(n, INF);
  queue<int> q;
  q.push(s);
  d[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : to[u]) {
      if (d[v] != INF) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }

  return d;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  --u, --v;
  vector<int> to[n];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> d1 = calcDist(u, n, to);
  vector<int> d2 = calcDist(v, n, to);

  int mx = 0;
  rep(i, n) {
    if (d2[i] <= d1[i]) continue;
    mx = max(mx, d2[i]);
  }

  int ans = mx - 1;
  cout << ans << endl;
  return 0;
}
