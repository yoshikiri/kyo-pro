#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void bfs(int n, ll *d, vector<P> *t) {
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &p : t[u]) {
      if (d[p.first] == INF) {
        d[p.first] = d[u] + p.second;
        q.push(p.first);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<P> t[n];

  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    t[u].push_back(make_pair(v, w));
    t[v].push_back(make_pair(u, w));
  }

  ll d[n];
  rep(i, n) d[i] = INF;
  d[0] = 0;
  bfs(n, d, t);

  rep(i, n) { cout << (d[i] % 2 == 0 ? 0 : 1) << '\n'; }

  return 0;
}
