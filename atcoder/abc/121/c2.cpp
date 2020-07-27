#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> d;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    d.push_back({a, b});
  }

  sort(d.begin(), d.end());
  ll ans = 0;
  rep(i, n) {
    int buy = min(m, d[i].second);
    ans += (ll)d[i].first * buy;
    m -= buy;
  }
  cout << ans << endl;
  return 0;
}
