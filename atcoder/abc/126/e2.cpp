#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  int same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -p[find(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    uf.unite(x, y);
  }

  set<int> s;
  rep(i, n) s.insert(uf.find(i));
  cout << s.size() << endl;
  return 0;
}
