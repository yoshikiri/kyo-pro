#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 2);
  a[0] = 0;
  a[m + 1] = n + 1;
  rep(i, m) cin >> a[i + 1];
  sort(a.begin(), a.end());
  vector<int> d;
  rep(i, m + 1) { d.push_back(a[i + 1] - a[i] - 1); }
  int mn = 1001001001;
  for (auto x : d) {
    if (x != 0) mn = min(mn, x);
  }

  int ans = 0;
  for (auto x : d) {
    ans += (x + mn - 1) / mn;
  }
  cout << ans << endl;
  return 0;
}
