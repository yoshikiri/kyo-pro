#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> ans(n);
  int cnt = 0;
  rep(c, 2) {
    rep(i, n) {
      if (s[i] == 'R')
        ++cnt;
      else {
        ans[i] += cnt / 2;
        ans[i - 1] += (cnt + 1) / 2;
        cnt = 0;
      }
    }

    reverse(s.begin(), s.end());
    reverse(ans.begin(), ans.end());
    rep(i, n) {
      if (s[i] == 'L')
        s[i] = 'R';
      else
        s[i] = 'L';
    }
  }

  rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
