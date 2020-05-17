#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAX = 100005;
const int INF = 1 << 30;
vector<int> a[MAX];
int pr[MAX];

void dijkstra(int n) {
  int d[n + 1];
  rep(i, n + 1) {
    d[i] = INF;
    pr[i] = -1;
  }

  priority_queue<P> q;

  d[1] = 0;
  q.push(make_pair(0, 1));
  while (!q.empty()) {
    auto p = q.top();
    q.pop();

    int u = p.second;
    int c = -p.first;
    if (d[u] < c) continue;

    for (auto v : a[u]) {
      if (d[v] == INF) {
        if (d[u] + 1 < d[v]) {
          d[v] = d[u] + 1;
          pr[v] = u;
          q.push(make_pair(-d[v], v));
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  dijkstra(n);

  cout << "Yes" << '\n';
  for (int i = 2; i < n + 1; ++i) { cout << pr[i] << '\n'; }

  return 0;
}
