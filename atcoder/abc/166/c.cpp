#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  std::cin >> n >> m;
  int h[n];
  rep(i, n) std::cin >> h[i];

  std::vector<std::vector<int>> r(n);

  int a, b;
  rep(i, m) {
    std::cin >> a >> b;
    --a;
    --b;
    if (std::find(r[a].begin(), r[a].end(), b) == r[a].end()) r[a].push_back(b);
    if (std::find(r[b].begin(), r[b].end(), a) == r[b].end()) r[b].push_back(a);
  }

  int cnt = 0;
  rep(i, n) {
    int v = i, maxh = h[i];
    for (int u : r[i]) {
      // printf("i: %d(%d), u:, %d(%d)\n", i, h[i], u, h[u]);
      if (maxh <= h[u]) {
        v = u;
        break;
      }
    }
    if (v == i) ++cnt;
  }

  std::cout << cnt << '\n';

  return 0;
}
