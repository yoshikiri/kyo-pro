#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int x, n;
  cin >> x >> n;
  set<int> p;
  rep(i, n) {
    int x;
    cin >> x;
    p.insert(x);
  }

  int ans = -1;
  for (int i = -200; i <= 200; ++i) {
    if (p.find(i) != p.end()) continue;
    if (abs(x - i) < abs(x - ans)) ans = i;
  }
  cout << ans << endl;
  return 0;
}
