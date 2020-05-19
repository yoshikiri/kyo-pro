#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> p;

  rep(i, m) {
    int s, c;
    cin >> s >> c;
    --s;
    p.push_back({s, c});
  }

  rep(i, 1000) {
    int x = i / 10;
    vector<int> d{i % 10};
    while (x > 0) {
      d.push_back(x % 10);
      x /= 10;
    }

    reverse(d.begin(), d.end());

    if (d.size() != n) continue;

    bool ok = true;
    rep(j, m) {
      if (d[p[j].first] != p[j].second) ok = false;
    }

    if (ok) {
      for (int v : d) {
        cout << v;
      }
      cout << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';

  return 0;
}
