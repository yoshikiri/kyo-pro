#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  int ans = 0, cur = 0;
  priority_queue<int> pq;
  for (int i = 1; i <= m; ++i) {
    while (cur < n && v[cur].first <= i) {
      pq.push(v[cur].second);
      ++cur;
    }
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}
