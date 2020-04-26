#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct DisjointSet {
  std::vector<int> rank, p;

  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);

    rep(i, size) makeSet(i);
  }

  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }

  void unite(int x, int y) { link(findSet(x), findSet(y)); }

  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else if (rank[x] < rank[y]) {
      p[x] = y;
    } else {
      p[y] = x;
      rank[x]++;
    }
  }

  int findSet(int x) {
    if (p[x] == x) return x;
    return p[x] = findSet(p[x]);
  }

  int same(int x, int y) { return findSet(x) == findSet(y); }
};

int main() {
  int n, q;
  std::cin >> n >> q;

  DisjointSet ds(n);

  int com, x, y;
  rep(i, q) {
    std::cin >> com >> x >> y;
    if (com == 0)
      ds.unite(x, y);
    else
      std::cout << ds.same(x, y) << '\n';
  }
  return 0;
}
