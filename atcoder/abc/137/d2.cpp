#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> arb(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    arb[i] = make_pair(a, b);
  }

  sort(arb.begin(), arb.end());

  int ans = 0;
  priority_queue<P> pq;
  int k = 0;
  for (int i = 1; i <= m; ++i) {
    while (arb[k].first <= i) {
      pq.push(make_pair(arb[k].second, arb[k].first));
      ++k;
    }

    if (pq.empty()) continue;

    ans += pq.top().first;
    pq.pop();
  }

  cout << ans << endl;
  return 0;
}
