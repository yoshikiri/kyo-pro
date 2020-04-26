#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int SIZE = 10000;
const int INF = 1 << 21;
std::vector<std::pair<int, int>> a[SIZE];
int d[SIZE];

void dijkstra(int s, int n) {
  std::priority_queue<std::pair<int, int>> q;

  rep(i, n) { d[i] = INF; }
  d[s] = 0;

  q.push(std::make_pair(0, s));

  while (!q.empty()) {
    auto p = q.top();
    q.pop();

    int u = p.second;
    if (d[u] < (-1) * p.first) continue;

    for (auto p : a[u]) {
      int v = p.first;
      if (d[v] > d[u] + p.second) {
        d[v] = d[u] + p.second;
        q.push(std::make_pair((-1) * d[v], v));
      }
    }
  }
}

int main() {
  int n;
  std::cin >> n;

  rep(i, n) {
    int u, k, v, c;
    std::cin >> u >> k;
    rep(j, k) {
      std::cin >> v >> c;
      a[u].push_back(std::make_pair(v, c));
    }
  }

  dijkstra(0, n);
  rep(i, n) { std::cout << i << ' ' << d[i] << '\n'; }

  return 0;
}
