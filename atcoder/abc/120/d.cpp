#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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

  int same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -p[find(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> p;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    p.push_back({a, b});
  }

  UnionFind uf(n);

  vector<ll> ans;

  ll now = (ll)n * (ll)(n - 1) / 2LL;
  ans.push_back(now);

  for (auto it = p.rbegin(); it != p.rend() - 1; ++it) {
    int a = it->first, b = it->second;

    ll as = uf.size(a), bs = uf.size(b);
    bool ok = uf.unite(a, b);

    if (ok) now -= as * bs;
    now = now < 0 ? 0 : now;
    ans.push_back(now);
  }

  for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
    cout << *it << '\n';
  }

  return 0;
}
