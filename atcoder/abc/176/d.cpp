#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

const int INF = 1001001001;
int cnt[1005][1005];
char s[1005][1005];
int h, w;

void bfs(P p, int c, queue<P> &sq) {
  queue<P> q;
  q.push(p);
  sq.push(p);
  cnt[p.first][p.second] = c;
  while (!q.empty()) {
    P u = q.front();
    q.pop();
    rep(i, 4) {
      int ni = u.first + dy[i];
      int nj = u.second + dx[i];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (cnt[ni][nj] != INF) continue;
      cnt[ni][nj] = c;
      q.push({ni, nj});
      sq.push({ni, nj});
    }
  }
}

void skip(queue<P> &sq, int c) {
  queue<P> tmp(sq);
  queue<P> clear;
  swap(sq, clear);
  while (!tmp.empty()) {
    auto u = tmp.front();
    tmp.pop();
    for (int dy = -2; dy <= 2; ++dy) {
      for (int dx = -2; dx <= 2; ++dx) {
        int ni = u.first + dy;
        int nj = u.second + dx;
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (cnt[ni][nj] != INF) continue;
        cnt[ni][nj] = c;
        sq.push({ni, nj});
      }
    }
  }
}

int main() {
  cin >> h >> w;
  P c, d;
  cin >> c.first >> c.second, --c.first, --c.second;
  cin >> d.first >> d.second, --d.first, --d.second;
  rep(i, h) rep(j, w) cin >> s[i][j];

  rep(i, 1005) rep(j, 1005) cnt[i][j] = INF;

  int e = 0;
  queue<P> sq;
  sq.push(c);
  while (!sq.empty() && cnt[d.first][d.second] == INF) {
    queue<P> tmp(sq);
    queue<P> clear;
    swap(sq, clear);
    while (!tmp.empty()) {
      P u = tmp.front();
      tmp.pop();
      bfs(u, e, sq);
    }
    ++e;
    skip(sq, e);
  }

  int ans = cnt[d.first][d.second];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
