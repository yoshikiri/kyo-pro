#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int INF = 1001001001;

int s[25][25];

int bfs(int v, int h, int w) {
  int n = h * w;
  vector<int> d(n, INF);
  d[v] = 0;

  queue<int> q;
  q.push(v);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int i = u / w, j = u % w;
    auto f = [w](int a, int b) { return a * w + b; };

    vector<int> to;
    if (i - 1 >= 0) to.push_back(f(i - 1, j));
    if (j + 1 < w) to.push_back(f(i, j + 1));
    if (i + 1 < h) to.push_back(f(i + 1, j));
    if (j - 1 >= 0) to.push_back(f(i, j - 1));

    for (auto t : to) {
      int a = t / w, b = t % w;
      if (s[a][b]) continue;
      if (d[t] != INF) continue;
      d[t] = d[u] + 1;
      q.push(t);
    }
  }

  int mx = 0;
  rep(i, n) {
    if (d[i] == INF) continue;
    mx = max(mx, d[i]);
  }
  return mx;
}

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    char a;
    cin >> a;
    if (a == '.')
      s[i][j] = 0;
    else
      s[i][j] = 1;
  }

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (s[i][j]) continue;
      int v = i * w + j;
      int mx = bfs(v, h, w);
      ans = max(ans, mx);
    }
  }

  cout << ans << endl;
  return 0;
}
