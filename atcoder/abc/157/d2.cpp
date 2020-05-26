#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  bool unite(int x, int y) {
    x = root(x), y = root(y);

    if (x == y) return false;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  int root(int x) {
    if (p[x] < 0) return x;
    return p[x] = root(p[x]);
  }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -p[root(x)]; }
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  UnionFind uf(n);
  vector<int> deg(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++deg[a];
    ++deg[b];
    uf.unite(a, b);
  }

  vector<int> bl[n];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    bl[a].push_back(b);
    bl[b].push_back(a);
  }

  rep(i, n) {
    int ans = uf.size(i) - 1 - deg[i];
    for (auto v : bl[i]) {
      if (uf.same(i, v)) --ans;
    }
    cout << ans;
    if (i != n - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
