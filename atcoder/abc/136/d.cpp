#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector<int> l, r;
  rep(i, n - 1) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      r.push_back(i);
      l.push_back(i + 1);
    }
  }

  vector<int> ans(n);
  rep(i, n) {
    std::vector<int>::iterator it;
    if (s[i] == 'L')
      it = lower_bound(l.begin(), l.end(), i);
    else
      it = lower_bound(r.begin(), r.end(), i);

    if (i == *it)
      ++ans[i];
    else {
      int d;
      if (s[i] == 'L') {
        if (l.size() != 1)
          d = *(--it);
        else
          d = l.back();
      } else
        d = *it;

      if ((i - d) % 2 == 0)
        ++ans[d];
      else {
        if (s[d] == 'R')
          ++ans[d + 1];
        else
          ++ans[d - 1];
      }
    }
  }

  rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

  return 0;
}
