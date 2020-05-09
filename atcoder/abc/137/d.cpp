#include <algorithm>
#include <iostream>
#include <vector>

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
    arb[i] = make_pair(b, a);
  }

  sort(arb.begin(), arb.end());

  int ans = 0;

  for (int res = m; res >= 0; --res) {
    for (int i = arb.size() - 1; i >= 0; --i) {
      if (arb[i].second <= res) {
        ans += arb[i].first;
        arb.erase(arb.begin() + i);
        break;
      } else {
        arb.erase(arb.begin() + i);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
