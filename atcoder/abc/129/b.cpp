#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int w[n];
  rep(i, n) cin >> w[i];

  int s[n + 1];
  s[0] = 0;
  rep(i, n) s[i + 1] = s[i] + w[i];
  int sum = 0;
  rep(i, n) sum += w[i];

  int ans = 1001001001;
  rep(i, n) {
    int res = sum - s[i];
    int now = abs(s[i] - res);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
