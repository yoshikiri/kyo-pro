#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> r(n), d(n);
  vector<multiset<int>> ms(200000);
  multiset<int> mx;
  rep(i, n) {
    cin >> r[i];
    cin >> d[i];
    --d[i];
    ms[d[i]].insert(r[i]);
  }

  for (auto s : ms) {
    if (s.empty()) continue;
    mx.insert(*s.rbegin());
  }

  rep(iq, q) {
    int i, t;
    cin >> i >> t;
    --i, --t;
    int x = *ms[d[i]].rbegin();
    ms[d[i]].erase(ms[d[i]].find(r[i]));
    if (!ms[d[i]].empty()) {
      int ax = *ms[d[i]].rbegin();
      if (x != ax) {
        mx.erase(mx.find(x));
        mx.insert(ax);
      }
    } else {
      mx.erase(mx.find(x));
    }

    if (ms[t].empty()) {
      ms[t].insert(r[i]);
      int ax = *ms[t].rbegin();
      mx.insert(ax);
    } else {
      x = *ms[t].rbegin();
      ms[t].insert(r[i]);
      int ax = *ms[t].rbegin();
      if (x != ax) {
        mx.erase(mx.find(x));
        mx.insert(ax);
      }
    }
    d[i] = t;
    cout << *mx.begin() << endl;
  }

  return 0;
}
