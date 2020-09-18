#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int s;
      cin >> s;
      --s;
      a[s] |= 1 << i;
    }
  }
  int p = 0;
  rep(i, m) {
    int x;
    cin >> x;
    p |= x << i;
  }

  int ans = 0;
  rep(s, 1 << n) {
    int t = 0;
    rep(i, n) {
      if (s >> i & 1) {
        t ^= a[i];
      }
    }
    if (t == p) ++ans;
  }
  cout << ans << endl;
  return 0;
}
