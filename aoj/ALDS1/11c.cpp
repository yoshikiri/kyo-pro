#include <iostream>
#include <queue>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1 << 21;

int main() {
  int n;
  std::cin >> n;

  int a[n][n];

  rep(i, n) rep(j, n) a[i][j] = 0;

  rep(i, n) {
    int u, k;
    std::cin >> u >> k;
    rep(j, k) {
      int v;
      std::cin >> v;
      a[u - 1][v - 1] = 1;
    }
  }

  int d[n];
  rep(i, n) d[i] = INF;
  d[0] = 0;

  std::queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    rep(j, n) {
      if (a[u][j] && d[j] == INF) {
        d[j] = d[u] + 1;
        q.push(j);
      }
    }
  }

  rep(i, n) std::cout << i + 1 << ' ' << (d[i] == INF ? -1 : d[i]) << '\n';

  return 0;
}
