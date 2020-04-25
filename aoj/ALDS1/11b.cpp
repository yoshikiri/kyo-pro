#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int SIZE = 101;
int d[SIZE], f[SIZE], a[SIZE][SIZE];
int t = 1;

void dfs(int u, int n) {
  d[u] = t;
  t++;
  rep(i, n) {
    if (a[u][i] && d[i] == 0 && f[i] == 0) dfs(i, n);
  }
  f[u] = t;
  t++;
}

int main() {
  int n;
  std::cin >> n;

  rep(i, n) rep(j, n) a[i][j] = 0;

  rep(i, n) {
    int u, k, v;
    std::cin >> u >> k;
    rep(j, k) {
      std::cin >> v;
      a[u - 1][v - 1] = 1;
    }
  }

  rep(i, n) if (d[i] == 0 && f[i] == 0) dfs(i, n);

  rep(i, n) { std::cout << i + 1 << ' ' << d[i] << ' ' << f[i] << '\n'; }

  return 0;
}
