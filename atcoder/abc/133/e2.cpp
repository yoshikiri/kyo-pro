#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> to[n];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  int root = -1;
  queue<int> q;
  vector<int> p(n, -1);
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : to[u]) {
      if (v == p[u]) continue;
      p[v] = u;
      q.push(v);
    }
  }
  rep(i, n) if (p[i] == -1) root = i;

  ll ans = k;
  q.push(root);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int d = k - 2;
    if (u == root) ++d;
    for (auto v : to[u]) {
      if (v == p[u]) continue;
      ans = ans * d % mod;
      --d;
      q.push(v);
    }
  }

  cout << ans << endl;

  return 0;
}
