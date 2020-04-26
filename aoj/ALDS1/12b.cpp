#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int SIZE = 101;
const int INF = 1 << 21;
int d[SIZE], state[SIZE];

void dijkstra(int s, int n, int **a) {
  rep(i, n) { d[i] = INF; }
  d[s] = 0;

  while (1) {
    int u = -1, minv = INF;
    rep(i, n) {
      if (d[i] < minv && state[i] != 1) {
        u = i;
        minv = d[i];
      }
    }

    if (u == -1) break;

    state[u] = 1;

    rep(i, n) {
      if (a[u][i] != INF) {
        int v = i, w = a[u][i];
        if (state[v] == 1) continue;
        if (d[v] > d[u] + w) { d[v] = d[u] + w; }
      }
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  int **a = new int *[n];
  rep(i, n) a[i] = new int[n];

  rep(i, n) rep(j, n) a[i][j] = INF;

  rep(i, n) {
    int u, k, v, c;
    std::cin >> u >> k;
    rep(j, k) {
      std::cin >> v >> c;
      a[u][v] = c;
    }
  }

  dijkstra(0, n, a);
  rep(i, n) { std::cout << i << ' ' << d[i] << '\n'; }

  return 0;
}
