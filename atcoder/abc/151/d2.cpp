#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;

  char s[h][w];
  rep(i, h) rep(j, w) { cin >> s[i][j]; }

  const int INF = 1001001001;
  int ans = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') continue;

    vector<vector<int>> d(h, vector<int>(w, INF));
    d[i][j] = 0;

    queue<P> q;
    q.push({i, j});

    while (!q.empty()) {
      P u = q.front();
      q.pop();

      ans = max(ans, d[u.first][u.second]);

      rep(dir, 4) {
        int ni = u.first + di[dir];
        int nj = u.second + dj[dir];

        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (d[ni][nj] != INF) continue;
        d[ni][nj] = d[u.first][u.second] + 1;
        q.push({ni, nj});
      }
    }
  }

  cout << ans << endl;
  return 0;
}
