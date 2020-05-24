#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int dp[100005];

int solve(int v, vector<int> *to) {
  if (dp[v] != -1) return dp[v];

  int res = 0;
  for (auto nv : to[v]) { res = max(res, solve(nv, to) + 1); }

  return dp[v] = res;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> to[n];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    to[x].push_back(y);
  }

  rep(i, n) dp[i] = -1;
  int ans = 0;
  rep(i, n) ans = max(ans, solve(i, to));

  cout << ans << endl;
  return 0;
}
