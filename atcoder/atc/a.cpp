#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int m[510][510];
int close[510][510];
int h, w;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int i, int j) {
  if (close[i][j])
    return;

  close[i][j] = true;

  rep(d, 4) {
    int ni = i + dy[d];
    int nj = j + dx[d];
    if (ni < 0 || ni >= h || nj < 0 || nj >= w)
      continue;
    if (m[ni][nj] == 1)
      continue;
    if (close[ni][nj])
      continue;
    dfs(ni, nj);
  }
}

int main() {
  cin >> h >> w;
  int si, sj, gi, gj;
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    m[i][j] = (c == '#' ? 1 : 0);
    if (c == 's') {
      si = i;
      sj = j;
    }
    if (c == 'g') {
      gi = i;
      gj = j;
    }
  }

  dfs(si, sj);
  if (close[gi][gj])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
