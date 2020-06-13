#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

vector<int> to[200005];
vector<int> ans;

void dfs(int u, int p = -1) {
  for (auto v : to[u]) {
    if (v == p) continue;
    ans[v] += ans[u];
    dfs(v, u);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  ans.resize(n);

  rep(i, q) {
    int p, x;
    cin >> p >> x;
    --p;
    ans[p] += x;
  }

  dfs(0);
  rep(i, n) cout << ans[i] << endl;
  return 0;
}
