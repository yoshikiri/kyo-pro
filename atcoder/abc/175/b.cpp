#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int l[n];
  rep(i, n) { cin >> l[i]; }

  int ans = 0;
  rep(i, n) {
    rep(j, i) {
      rep(k, j) {
        if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j] &&
            l[i] != l[j] && l[j] != l[k] && l[k] != l[i])
          ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
