#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  int x[m], y[m], z[m];
  rep(i, m) {
    cin >> x[i] >> y[i] >> z[i];
    --x[i];
    --y[i];
  }

  int p[n], cnt[n];
  rep(i, n) {
    p[i] = 0;
    cnt[i] = 0;
  }

  rep(i, m) {
    ++cnt[x[i]];
    ++cnt[y[i]];
  }

  vector<pair<int, pair<int, int>>> list(m);
  rep(i, m) {
    list[i] = make_pair(max(cnt[x[i]], cnt[y[i]]), make_pair(x[i], y[i]));
  }
  sort(list.begin(), list.end(), greater<>());
  // sort(list.begin(), list.end());

  for (auto &p : list) {
    printf("%d, %d, %d\n", p.first, p.second.first, p.second.second);
  }

  int ans = 0;
  rep(i, m) {
    int x = list[i].second.first;
    int y = list[i].second.second;
    // cout << "x, y: " << x << ", " << y << '\n';

    if (p[x] || p[y]) {
      p[x] = p[y] = 1;
      continue;
    }
    p[x] = p[y] = 1;
    ++ans;
  }

  rep(i, n) {
    if (!p[i]) ++ans;
  }

  cout << ans << '\n';

  return 0;
}
