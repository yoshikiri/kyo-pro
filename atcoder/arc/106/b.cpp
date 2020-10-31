#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;

    if (-p[x] < -p[y])
      swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  int root(int x) {
    if (p[x] < 0)
      return x;
    return root(p[x]);
  }

  int size(int x) { return -p[root(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[n];
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  UnionFind uf(n);
  rep(i, m) {
    int c, d;
    cin >> c >> d;
    uf.unite(--c, --d);
  }

  vector<ll> s(n);
  rep(i, n) s[uf.root(i)] += b[i] - a[i];
  bool ans = true;
  rep(i, n) if (s[i] != 0) ans = false;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
