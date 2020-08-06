#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> x[2];
  rep(i, n) {
    int a;
    cin >> a;
    x[0].push_back(a);
  }

  sort(x[0].begin(), x[0].end());
  for (int i = 1; i <= 2 * n; ++i) {
    if (*lower_bound(x[0].begin(), x[0].end(), i) == i)
      continue;
    x[1].push_back(i);
  }

  int a = 0, t = 0;
  while (x[0].size() && x[1].size()) {
    auto it = lower_bound(x[t].begin(), x[t].end(), a);
    if (it == x[t].end()) {
      a = 0;
    } else {
      a = *it;
      x[t].erase(it);
    }
    t = 1 - t;
  }

  rep(i, 2) cout << x[1 - i].size() << endl;
  return 0;
}
