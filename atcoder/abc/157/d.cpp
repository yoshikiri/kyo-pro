#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct UnionFind {
  vector<int> p;

  UnionFind(int n = 0) : p(n, -1) {}

  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return false;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return true;
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return -p[find(x)]; }
};

int deg[100005];
vector<int> block[100005];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  UnionFind uf(n);
  // vector<int> deg(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ++deg[a];
    ++deg[b];
    uf.unite(a, b);
  }

  // vector<int> block[n];

  rep(i, k) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    block[c].push_back(d);
    block[d].push_back(c);
  }

  rep(i, n) {
    int ans = uf.size(i) - deg[i] - 1;
    for (int v : block[i]) {
      if (uf.same(i, v)) --ans;
    }

    cout << ans << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}
