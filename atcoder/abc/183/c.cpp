#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int t[n][n];
  rep(i, n) rep(j, n) cin >> t[i][j];
  vector<int> p(n);
  rep(i, n) p[i] = i;

  int ans = 0;
  do {
    if (p[0] != 0) continue;
    int now = 0;
    rep(i, n - 1) { now += t[p[i]][p[i + 1]]; }
    now += t[p[n - 1]][0];
    if (now == k) ++ans;
  } while (next_permutation(p.begin(), p.end()));

  cout << ans << endl;
  return 0;
}
