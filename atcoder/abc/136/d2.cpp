#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> r;
  rep(i, n - 1) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      r.push_back(i);
    }
  }

  vector<int> ans(n);
  rep(i, n) {
    int idx;
    if (s[i] == 'R')
      idx = *lower_bound(r.begin(), r.end(), i);
    else
      idx = *(lower_bound(r.begin(), r.end(), i) - 1) + 1;
    int d = abs(i - idx);
    if (d % 2 == 0) {
      ++ans[idx];
    } else {
      if (s[i] == 'R')
        ++idx;
      else
        --idx;
      ++ans[idx];
    }
  }

  rep(i, n) printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
  return 0;
}
