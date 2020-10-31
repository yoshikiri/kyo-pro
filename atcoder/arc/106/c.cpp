#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  if (n == 1 && m == 0) {
    cout << 1 << " " << 2 << endl;
    return 0;
  }

  if (m < 0 || m > n - 2) {
    cout << -1 << endl;
    return 0;
  }

  vector<P> v;
  int x = 2;
  int z = 0;
  rep(i, n - 1) {
    if (i == m) {
      v.push_back({x, x + 2});
      z = x + 1;
      x += 3;
    } else {
      v.push_back({x, x + 1});
      x += 2;
    }
  }

  v.push_back({1, z});

  for (auto p : v)
    printf("%d %d\n", p.first, p.second);
  return 0;
}
