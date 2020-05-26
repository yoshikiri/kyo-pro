#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  set<int> a[26];
  rep(i, n) { a[s[i] - 'a'].insert(i); }

  rep(qn, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      if (s[i] == c) continue;
      a[s[i] - 'a'].erase(i);
      a[c - 'a'].insert(i);
      s[i] = c;
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = 0;
      rep(i, 26) {
        auto it = a[i].lower_bound(l);
        if (it == a[i].end()) continue;
        if (l <= *it && *it <= r) ++ans;
      }
      cout << ans << endl;
    }
  }

  return 0;
}
