#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int neg = 0;
  ll sum = 0;
  rep(i, n) {
    neg += (a[i] < 0);
    sum += abs(a[i]);
  }

  ll ans = sum;
  if (neg & 1) {
    sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
    ans -= (ll)2 * abs(a[0]);
  }
  cout << ans << endl;
  return 0;
}
