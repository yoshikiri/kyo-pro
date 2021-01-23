#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

vector<int> a, d;
vector<vector<int>> to;
const int INF = 1001001001;

int f(int u) {
  cout << u << endl;
  if (d[u] != -2 * INF) return d[u];
  if (to[u].empty()) return a[u];
  for (int v : to[u]) {
    d[u] = max(d[u], f(v));
  }
  return d[u];
}

int main() {
  int n, m;
  cin >> n >> m;
  a.resize(n);
  d = vector(n, -2 * INF);
  to.resize(n);

  rep(i, n) cin >> a[i];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    to[x].push_back(y);
  }

  int ans = -INF;
  rep(i, n) {
    if (to[i].empty()) continue;
    ans = max(ans, f(i) - a[i]);
  }
  cout << ans << endl;
  return 0;
}