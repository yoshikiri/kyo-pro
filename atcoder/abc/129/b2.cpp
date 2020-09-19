#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  rep(i, n) cin >> w[i];

  int sum = 0;
  rep(i, n) sum += w[i];

  int ans = 1001001001;
  for (int k = 1; k < n; ++k) {
    int l = 0;
    rep(i, k) l += w[i];
    int r = sum - l;
    ans = min(ans, abs(r - l));
  }
  cout << ans << endl;
  return 0;
}
