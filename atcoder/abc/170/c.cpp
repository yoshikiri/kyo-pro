#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, n;
  cin >> x >> n;

  vector<int> q(102);
  rep(i, 102) { q[i] = i; }

  rep(i, n) {
    int p;
    cin >> p;
    q.erase(remove(q.begin(), q.end(), p), q.end());
  }

  int ans = 1001001001;
  for (auto u : q) {
    if (abs(ans - x) > abs(u - x)) ans = u;
  }

  cout << ans << endl;
  return 0;
}
