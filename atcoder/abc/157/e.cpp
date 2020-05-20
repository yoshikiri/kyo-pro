#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int nq;
  cin >> nq;

  vector<set<int>> al(26);
  rep(i, n) { al[s[i] - 'a'].insert(i); }

  rep(qi, nq) {
    int q;
    cin >> q;
    if (q == 1) {
      int i;
      char c;
      cin >> i >> c;
      --i;
      al[s[i] - 'a'].erase(i);
      s[i] = c;
      al[c - 'a'].insert(i);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      int ans = 0;
      rep(i, 26) {
        auto it = al[i].lower_bound(l);
        if (it != al[i].end() && *it <= r) ++ans;
      }
      // for (auto a : al) {
      //   auto idx = a.lower_bound(l);
      //   if (idx != a.end() && *idx <= r) ++ans;
      // }
      printf("%d\n", ans);
    }
  }
  return 0;
}
