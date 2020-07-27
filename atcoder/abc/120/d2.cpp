#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (size(x) < size(y)) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  int size(int x) { return -p[root(x)]; }

  int root(int x) {
    if (p[x] < 0) return x;
    return p[x] = root(p[x]);
  }

  bool same(int x, int y) { return root(x) == root(y); }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> d(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    d[i] = P(a, b);
  }

  UnionFind uf(n);
  ll now = (ll)n * (n - 1) / 2;
  vector<ll> ans(m);
  for (int i = m - 1; i >= 0; --i) {
    ans[i] = now;
    int x = d[i].first;
    int y = d[i].second;
    ll sx = uf.size(x), sy = uf.size(y);
    if (uf.unite(x, y)) now -= sx * sy;
    now = max(now, 0LL);
  }

  rep(i, m) cout << ans[i] << endl;
  return 0;
}
