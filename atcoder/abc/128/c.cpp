#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s[m];
  rep(i, m) {
    int k;
    cin >> k;
    s[i].resize(k);
    rep(j, k) {
      cin >> s[i][j];
      --s[i][j];
    }
  }
  int p[m];
  rep(i, m) cin >> p[i];

  int ans = 0;
  rep(sn, 1 << n) {
    int on[n];
    rep(i, n) on[i] = sn >> i & 1;

    bool ok = true;
    rep(i, m) {
      int sum = 0;
      for (auto id : s[i]) sum += on[id];
      if (sum % 2 != p[i]) ok = false;
    }
    if (ok) ++ans;
  }

  cout << ans << endl;
  return 0;
}
