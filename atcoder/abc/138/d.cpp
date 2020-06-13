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

  vector<int> cnt(n);
  rep(i, nq) {
    int p, x;
    cin >> p >> x;
    --p;
    cnt[p] += x;
  }

  vector<int> ans(n), close(n);
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    close[u] = 1;
    ans[u] += cnt[u];

    for (auto v : to[u]) {
      if (close[v]) continue;
      cnt[v] += cnt[u];
      q.push(v);
    }
  }

  rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

  return 0;
}
