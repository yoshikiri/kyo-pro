#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

const int INF = 1001001001;

int main() {
  int h, w;
  cin >> h >> w;
  P c, d;
  cin >> c.first >> c.second;
  cin >> d.first >> d.second;
  --c.first, --c.second, --d.first, --d.second;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  priority_queue<pair<int, P>> pq;
  pq.push({0, c});
  vector<vector<int>> dist(h, vector<int>(w, INF));
  dist[c.first][c.second] = 0;
  while (!pq.empty()) {
    auto u = pq.top();
    pq.pop();
    int i = u.second.first;
    int j = u.second.second;
    int cost = u.first;
    if (dist[i][j] < -cost) continue;

    auto ok = [&](int a, int b) {
      if (a < 0 || a >= h || b < 0 || b >= w) return false;
      if (s[a][b] == '#') return false;
      return true;
    };

    rep(dir, 4) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (!ok(ni, nj)) continue;
      if (dist[ni][nj] > -cost) {
        dist[ni][nj] = -cost;
        pq.push({-cost, {ni, nj}});
      }
    }

    for (int di = -2; di <= 2; ++di) {
      for (int dj = -2; dj <= 2; ++dj) {
        int ni = i + di;
        int nj = j + dj;
        if (!ok(ni, nj)) continue;
        if (dist[ni][nj] > -cost + 1) {
          dist[ni][nj] = -cost + 1;
          pq.push({-cost + 1, {ni, nj}});
        }
      }
    }
  }

  int ans = dist[d.first][d.second];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
