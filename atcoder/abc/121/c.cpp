#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> v(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(a, b);
  }

  sort(v.begin(), v.end());
  ll sum = 0, ans = 0;
  rep(i, n) {
    rep(j, v[i].second) {
      if (sum >= m) break;
      ++sum;
      ans += v[i].first;
    }
  }

  cout << ans << endl;
  return 0;
}
