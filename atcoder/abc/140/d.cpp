#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> v;
  int cnt = 1;
  rep(i, n) {
    if (s[i] == s[i + 1])
      ++cnt;
    else {
      v.push_back(cnt);
      cnt = 1;
    }
  }
  int sz = v.size();
  int d = 0;
  for (auto x : v) d += x - 1;
  int ans = d + 2 * min(k, sz / 2);
  if (sz / 2 <= k) {
    if (sz % 2 == 0) --ans;
  }
  ans = min(ans, n - 1);
  cout << ans << endl;
  return 0;
}
