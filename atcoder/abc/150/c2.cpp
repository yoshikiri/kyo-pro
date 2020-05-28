#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void perm(int pos, int n, vector<int> &a, vector<bool> &used) {
  if (pos == n) {
    for (auto v : a) {
      cout << v;
    }
    cout << endl;
    return;
  }

  rep(i, n) {
    if (used[i]) continue;
    used[i] = true;
    a[pos] = i;
    perm(pos + 1, n, a, used);
    used[i] = false;
  }
}

int main() {
  // int n;
  // cin >> n;
  // vector<int> p(n), q(n);
  // rep(i, n) { cin >> p[i]; }
  // rep(i, n) { cin >> q[i]; }
  // vector<int> a(n);
  // rep(i, n) a[i] = i + 1;
  //
  // map<vector<int>, int> mp;
  // do {
  //   mp[a] = mp.size();
  //   for (auto v : a) {
  //     cout << v;
  //   }
  //   cout << endl;
  // } while (next_permutation(a.begin(), a.end()));
  //
  // int ans = abs(mp[p] - mp[q]);
  // cout << ans << endl;

  int n = 3;
  vector<int> a(n);
  vector<bool> used(n);
  perm(0, n, a, used);
  return 0;
}
