#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  sort(p.begin(), p.end());
  int ans = 0;
  rep(i, k) ans += p[i];
  cout << ans << endl;
  return 0;
}
