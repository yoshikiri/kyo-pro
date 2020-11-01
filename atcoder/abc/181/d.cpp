#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int m = min(n, 3);
  map<int, int> mp;
  rep(i, n)++ mp[s[i] - '0'];

  bool ans = false;
  rep(i, 1000) {
    if (i % 8 != 0) continue;

    string t = to_string(i);
    if ((int)t.size() > n) break;

    while ((int)t.size() < m) t = "0" + t;
    vector<int> x(m);
    rep(j, m) x[j] = t[j] - '0';

    rep(j, m)-- mp[x[j]];
    bool now = true;
    rep(j, m) now &= (mp[x[j]] >= 0);
    if (now) ans = true;
    rep(j, m)++ mp[x[j]];
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
