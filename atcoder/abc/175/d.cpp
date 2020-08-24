#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  int p[n], c[n];
  rep(i, n) cin >> p[i], --p[i];
  rep(i, n) cin >> c[i];

  ll ans = -1e18;
  rep(i, n) {
    int v = i;
    ll loopSum = 0;
    int loopLen = 0;

    while (1) {
      ++loopLen;
      loopSum += c[v];
      v = p[v];
      if (v == i) break;
    }

    ll path = 0;
    int cnt = 0;

    while (1) {
      ++cnt;
      path += c[v];

      if (cnt > k) break;

      int num = (k - cnt) / loopLen;
      ll score = path + max(0ll, loopSum) * num;
      ans = max(ans, score);

      v = p[v];
      if (v == i) break;
    }
  }

  cout << ans << endl;

  return 0;
}
