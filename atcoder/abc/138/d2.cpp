#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, nq;
  cin >> n >> nq;

  vector<int> to[n];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<int> add(n);
  rep(i, nq) {
    int p, x;
    cin >> p >> x;
    --p;
    add[p] += x;
  }

  vector<int> ans(n, -1);

  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans[u] = add[u];
    for (auto v : to[u]) {
      if (ans[v] != -1) continue;
      add[v] += add[u];
      q.push(v);
    }
  }

  rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
