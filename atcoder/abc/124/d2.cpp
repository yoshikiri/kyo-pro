#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> a;
  int cur = 0;
  int c = 1;
  rep(i, n) {
    if (s[i] == c + '0')
      ++cur;
    else {
      a.push_back(cur);
      cur = 1;
      c = 1 - c;
    }
  }
  a.push_back(cur);

  vector<int> sum(a.size() + 1);
  rep(i, a.size()) sum[i + 1] = sum[i] + a[i];

  int ans = 0;
  for (int i = 0; i < (int)a.size(); i += 2) {
    int last = min(i + 2 * k + 1, (int)sum.size() - 1);
    int now = sum[last] - sum[i];
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
