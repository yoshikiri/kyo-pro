#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> pos, neg;
  rep(i, n) {
    int a;
    cin >> a;
    if (a >= 0)
      pos.push_back(a);
    else
      neg.push_back(a);
  }

  ll ans = 0;
  for (auto x : pos) ans += x;
  for (auto x : neg) ans += abs(x);

  if (neg.size() % 2 == 1) {
    int mn = 1001001001;
    for (auto x : pos) mn = min(mn, x);
    for (auto x : neg) mn = min(mn, abs(x));
    ans -= (ll)2 * mn;
  }
  cout << ans << endl;

  return 0;
}
