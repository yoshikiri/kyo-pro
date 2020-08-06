#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int m;
  cin >> m;
  P s[m];
  rep(i, m) cin >> s[i].first >> s[i].second;
  int n;
  cin >> n;
  P t[n];
  set<P> ts;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    t[i] = {x, y};
    ts.insert({x, y});
  }

  P p = s[0];
  P sd[m];
  rep(i, m) {
    sd[i].first = s[i].first - p.first;
    sd[i].second = s[i].second - p.second;
  }

  rep(i, n) {
    bool ok = true;
    rep(j, m) {
      int x = t[i].first + sd[j].first;
      int y = t[i].second + sd[j].second;
      if (ts.find({x, y}) == ts.end()) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << t[i].first - p.first << " " << t[i].second - p.second << endl;
    }
  }
  return 0;
}
