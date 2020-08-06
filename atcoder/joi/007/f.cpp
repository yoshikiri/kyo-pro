#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> to(n, vector<int>(n, INF));
  rep(nq, k) {
    int t;
    cin >> t;
    if (t == 0) {
      int a, b;
      cin >> a >> b;
      --a, --b;

      vector<int> d(n, INF);
      d[a] = 0;
      priority_queue<P> q;
      q.push({-d[a], a});
      while (!q.empty()) {
        P u = q.top();
        q.pop();
        if (-u.first > d[u.second])
          continue;

        rep(v, n) {
          if (to[u.second][v] == INF)
            continue;
          if (d[v] < d[u.second] + to[u.second][v])
            continue;
          d[v] = d[u.second] + to[u.second][v];
          q.push({-d[v], v});
        }
      }

      if (d[b] != INF)
        printf("%d\n", d[b]);
      else
        printf("%d\n", -1);
    } else {
      int a, b, c;
      cin >> a >> b >> c;
      --a, --b;
      to[a][b] = min(to[a][b], c);
      to[b][a] = to[a][b];
    }
  }
  return 0;
}
